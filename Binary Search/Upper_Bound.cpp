

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            // upper bound found:
            return i;
        }
    }
    return n;
}

int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x)
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 4, 5, 6, 9, 9};
    int element = 9;

    // STL
    int index = upper_bound(arr.begin(), arr.end(), element) - arr.begin(); // returns index
    cout << " Index: " << index;

    int ind = upperBound(arr, element, arr.size());
    cout << "The upper bound is the index: " << ind << "\n";
    return 0;

    return 0;
}
