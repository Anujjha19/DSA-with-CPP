#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void sort012(int arr[], int n)
 //Using Three Pointer
{
    int low=0;
    int mid=0;
    int high=n-1;
    while( mid <= high){
        if( arr[mid] ==0){
            swap( arr[low] , arr[mid]);
            low++;
            mid++;
        }
        else if( arr[mid]==1){
            mid++;
        }
        else if( arr[mid] ==2){
            swap( arr[mid] , arr[high]);
            high--;
        }
    }
}
// Time Complexity: O(n), Only one traversal of the array is needed.
// Space Complexity: O(1), No extra space is required.



/* // Using Counter of Each
{

    int i, c0 = 0, c1 = 0, c2 = 0;
    for (i = 0; i < n; i++)
    {
        switch (arr[i])
        {
        case 0:
            c0++;
            break;
        case 1:
            c1++;
            break;
        case 2:
            c2++;
            break;
        }
    }
    i = 0;
    while (c0 > 0)
    {
        arr[i++] = 0;
        c0--;
    }
    while (c1 > 0)
    {
        arr[i++] = 1;
        c1--;
    }
    while (c2 > 0)
    {
        arr[i++] = 2;
        c2--;
    }
} // TC - O(N) & SC - O(1)
 */

int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    sort012(arr, n);
    cout << "Sorted Array : " << endl;
    printArray(arr, n);

    return 0;
}
