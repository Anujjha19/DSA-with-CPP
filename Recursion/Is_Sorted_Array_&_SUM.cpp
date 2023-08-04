#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n)
{
    if (n <= 1)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
    {
        bool otherRemainingPart = isSorted(arr + 1, n - 1);
        return otherRemainingPart;
    }
}

int getSum(int arr[], int size)
{
    // base case
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }
    int remainingPart = getSum(arr + 1, size - 1);
    int sum = arr[0] + remainingPart;
    return sum;
}
int main()
{
    int arr[5] = {2, 4, 9, 9, 9};
    int size = 5;

    int sum = getSum(arr, size);
    cout << "Sum is " << sum << endl;

    if (isSorted(arr, 5))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}