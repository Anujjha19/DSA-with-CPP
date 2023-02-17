#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high, int n)
{
    int ans[n];
    int left = low;
    int right = mid + 1;
    int i = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans[i] = arr[left];
            i++;
            left++;
        }
        else
        {
            ans[i] = arr[right];
            i++;
            right++;
        }
    }
    while (left <= mid)
    {
        ans[i] = arr[left];
        i++;
        left++;
    }
    while (right <= high)
    {
        ans[i] = arr[right];
        i++;
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
        
}co
void merge_sort(int arr[], int low, int high, int n)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;

    merge_sort(arr, low, mid, n);
    merge_sort(arr, mid + 1, high, n);

    merge(arr, low, mid, high, n);
}

int main()
{
    cout << " Enter N: ";
    int n;
    cin >> n;
    int arr[n];

    cout << "Enter Array Element : ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1, n);
    cout << "After selection sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
    return 0;
}