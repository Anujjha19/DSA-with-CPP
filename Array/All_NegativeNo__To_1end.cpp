#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void moveZeroes(int arr[], int n)
{
    int i=0;
    for(int j=0; j<n; j++){
        if(arr[j] < 0){
            if (i != j)
            swap(arr[j], arr[i]);
            i++;
        }
    }
} 
// Time complexity: O(N) 
// Auxiliary Space: O(1)

/* //Using Sorting
void moveZeroes(int arr[], int n){
        sort( arr , arr+n);
}

//Time Complexity: O(n*log(n))
//Auxiliary Space: O(n) */



int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int i, arr_size = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, arr_size);

    cout << "Array after Moving all Zeros at END is ";
    for (i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}
