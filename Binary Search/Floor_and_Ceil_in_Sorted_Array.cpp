#include <bits/stdc++.h>
using namespace std;

#include <algorithm>

using namespace std;

int getFloor(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (arr[mid] == x)
        {
            return arr[mid];
        }
        else if (arr[mid] < x)
        {
            ans = arr[mid];
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int getCeil(int arr[], int n, int x)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + ((e - s) / 2);
        if (arr[mid] == x)
        {
            return arr[mid];
        }
        else if (arr[mid] > x)
        {
            ans = arr[mid];
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
    // code here
    sort(arr, arr + n);
    int f = getFloor(arr, n, x);
    int c = getCeil(arr, n, x);
    return make_pair(f, c);
}

int main()
{
    int arr[] = {3, 4, 4, 7, 8, 10};
    int n = 6, x = 5;
    pair<int, int> ans = getFloorAndCeil(arr, n, x);
    cout << "The floor and ceil are: " << ans.first
         << " " << ans.second << endl;
    return 0;
}
