#include <bits/stdc++.h>
using namespace std;

int partitionQS(int arr[], int s, int e)
{
    int pivot = arr[s];

    int count = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    // placed pivot at right place
    int pivotIndex = s + count;

    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] >= pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

/* int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
 */

void quickSort(int arr[], int n, int s, int e)
{

    if (s >= e)
        return;

    int p = partitionQS(arr, s, e);

    quickSort(arr, n, s, p - 1);

    quickSort(arr, n, p + 1, e);
}

int main()
{
    int arr[5] = {4, 100, 55, 0, 1};
    int n = 5;

    quickSort(arr, n, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
