#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/* // Keepig The Count
int count = 0;
for (int i = 0; i < n; i++)
{
    if (arr[i] == 0)
    {
        count++;
    }
}
for (int i = 0; i < count; i++)
{
    arr[i] = 0;
}
for (int i = count; i < n; i++)
{
    arr[i] = 1;
}
 */
// Time Complexity : O(2n)  ≅ O(n)
// Auxiliary Space: O(1)

//Using Two Pointer
void segregate0and1(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        if (arr[start] == 1)
        {
            if (arr[end] != 1)
                swap(arr[start], arr[end]);
            end--;
        }
        else
            start++;
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1, 1};
    int i, arr_size = sizeof(arr) / sizeof(arr[0]);

    segregate0and1(arr, arr_size);

    cout << "Array after segregation is ";
    for (i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}
// Time Complexity : O(n)
// Auxiliary Space: O(1)