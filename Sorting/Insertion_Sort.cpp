#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        int j=i;

        while(  j > 0 && arr[j-1] > arr[j]){
            swap( arr[j-1] , arr[j]);
            j--;
        }
    }
}
//Recursion
void insertionSort(int arr[], int idx, int size)
{
   //base case
        if(idx == size)
            return;
        int curr = arr[idx];
        int j = idx - 1;
        while(j >= 0){
            if(curr < arr[j]){ // found greater value than curr shift to right
                arr[j + 1] = arr[j--];
            }
            else // Smaller element found
                break;
        }
        arr[j + 1] = curr; //place curr element at correct place

        // one part Done recursion will do other work;
        insertionSort(arr , idx + 1 , size);
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

    insertion_sort(arr, n);
    cout << "After selection sort: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
        insertionSort(arr, 0,n);

    cout << "\n";
    return 0;
}