#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void moveZeroes(int arr[], int n)
{
    int i=0;
    for(int j=0; j<n; j++){
        if(arr[j] !=0){
            swap(arr[j], arr[i]);
            i++;
        }
    }
}

int main()
{
    int arr[] = {0,1,0,3,12};
    int i, arr_size = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, arr_size);

    cout << "Array after Moving all Zeros at END is ";
    for (i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}
