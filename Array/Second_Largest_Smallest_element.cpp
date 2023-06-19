#include <bits/stdc++.h>
using namespace std;
void getElements(int arr[], int n)
{
    if (n == 0 || n == 1)
        cout << -1 << " " << -1 << endl; // edge case when only one element is present in array
    sort(arr, arr + n);
    int small = arr[1];

    int large = arr[n - 2];
    cout << "Second smallest is " << small << endl;
    cout << "Second largest is " << large << endl;
}
void second_large_small(int arr[], int n)
{
    int small = INT_MAX;
    int secondSmall = INT_MAX;
    int large = INT_MIN;
    int secondLarge = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        small = min(small, arr[i]);
        large = max(large, arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < secondSmall && arr[i] != small)
        {
            secondSmall = arr[i];
        }
        if (arr[i] > secondLarge && arr[i] != large)
        {
            secondLarge = arr[i];
        }
    }
    cout << "Second smallest is " << secondSmall << endl;
    cout << "Second largest is " << secondLarge << endl;
}

void secondLargest(int arr[], int n)
{
    int large = arr[0];
    int secondL = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            secondL = large;
            large = arr[i];
        }
    }
    cout << "Second Largest is : " << secondL << endl;
}

int main()
{
    int arr[] = {1, 2, 4, 6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    getElements(arr, n);

    cout << endl;
    second_large_small(arr, n);

    secondLargest(arr, n);
    return 0;
}
