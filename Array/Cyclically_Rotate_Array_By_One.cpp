#include<bits/stdc++.h>
using namespace std;

void rotateArray( int arr[] , int n){

    /* //By One  
    int x = arr[n - 1], i; 
    for (i = n - 1; i > 0; i--) 
    arr[i] = arr[i - 1];  
    arr[0] = x;  */

    int i=0; 
    int j= n-1;
    while(i!=j){
        swap(arr[i], arr[j]);
        i++; j--;
    }

}

int main()
{
    int arr[] ={1,2,3,4,5};
    int n= sizeof(arr) / sizeof(arr[0]);

    cout<< "Given Array is : " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    rotateArray(arr, n);

    cout << "\nRotated array is\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;

}