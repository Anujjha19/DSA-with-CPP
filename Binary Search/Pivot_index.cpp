#include <bits/stdc++.h>
using namespace std;

int pivotFind(vector<int> &arr, int x)
{
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= arr[0])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    // return high;
    return low;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = pivotFind(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}
