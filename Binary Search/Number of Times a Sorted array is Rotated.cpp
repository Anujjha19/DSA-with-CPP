#include <bits/stdc++.h>
using namespace std;

int countRotations_LS(int arr[], int n)
{
    int min = arr[0], min_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int countRotations_BS(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    //

    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        int next = arr[(mid + 1) % n];
        int prev = arr[(mid + n - 1) % n];
        if (arr[mid] <= prev && arr[mid] <= next)
            return mid;

        if (arr[mid] <= arr[j])
        {
            j = mid - 1;
        }
        else if (arr[i] <= arr[mid])
        {
            i = mid + 1;
        }
    }
    return 0;
}
/*
int findKRotation(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2; // search space is already sorted then arr[low] will always be  the minimum in that search space:
        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            // keep the minimum:
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            // Eliminate left half:
            low = mid + 1;
        }
        else
        { // if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
}
*/
int main()
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countRotations_BS(arr, n);
    return 0;
}