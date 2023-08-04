#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{

    if (low > high)
    {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    if (arr[mid] > key)
    {
        return binarySearch(arr, low, mid - 1, key);
    }
    return binarySearch(arr, mid + 1, high, key);
}

int main()
{
    int arr[] = {5, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 15;

    int index = binarySearch(arr, 0, size - 1, key);
    if (index != -1)
    {
        cout << "Element found at index: " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
