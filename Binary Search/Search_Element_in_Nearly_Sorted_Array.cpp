#include <bits/stdc++.h>
using namespace std;

int searchInNearlySorted(int arr[], int n, int k)
{
    int start = 0;
    int end = n - 1; // Corrected the array length
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }
        else if (mid - 1 >= start && arr[mid - 1] == k)
        {
            return mid - 1;
        }
        else if (mid + 1 <= end && arr[mid + 1] == k)
        {
            return mid + 1;
        }
        else if (arr[mid] > k)
        {
            end = mid - 2;
        }
        else
        {
            start = mid + 2;
        }
    }
    return -1;
}

// Driver Code
int main(void)
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 40;
    // int arr[] =  {10, 3, 40, 20, 50, 80, 70}
    // int  key = 90
    int result = searchInNearlySorted(arr, n, x);
    (result == -1)
        ? printf("Element is not present in the array")
        : printf("Element is present at index %d", result);
    return 0;
}
