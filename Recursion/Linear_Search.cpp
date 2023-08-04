#include <bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int key)
{
    if (size == 0)
    {
        return -1;
    }

    if (arr[size - 1] == key)
    {
        return size - 1;
    }
    return linearSearch(arr, size - 1, key);
    // if (arr[0] == key)
    // {
    //     return true ;
    // }
    // return linearSearch(arr+ 1, size - 1, key);
}

int main()
{
    int arr[] = {5, 10, 15, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 15;

    int index = linearSearch(arr, size, key);
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
