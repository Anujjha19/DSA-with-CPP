#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        bool alreadySorted = false;

        // for( int j =0 ; j < n-1 ; j++) { n-1 == i} will throw error when we check for last elemnt with ahead  of that
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
                alreadySorted = true;
            }
        } 
        if (alreadySorted == false)
            break;
    }
}

/*  // A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
  */

//Recursion Approach
void bubbleSort( int arr[] , int n){
    if( n==1 ) return;
    int count=0;
    for( int i=0; i<n; i++){
        if( arr[i] > arr[i+1]){
            swap( arr[i] , arr[i+1]);
            count++;
        }
    }
    if( count==0) return ;

    bubbleSort(arr , n-1);
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

    bubble_sort(arr, n);
    cout << "After selection sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}