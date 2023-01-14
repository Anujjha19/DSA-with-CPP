#include <iostream>
using namespace std;

//Using Recursion TC - O(N)
void reverseArray(int arr[], int start, int end)
{
    if( start >= end){
        return;
    }
    int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        reverseArray(arr , start+1, end-1 ); 
}

void printArray(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    int start = 0;
    int end = n - 1;
    cout << n;
    cout << endl;
    printArray(arr , 4);
    cout << endl;

    /* //Using Two Pointer TC - O(N )
        while( start < end){
            int temp = arr[start];
            arr[start]= arr[end];
            arr[end]= temp;
            start++;
            end--;
        } */
    cout << endl;
    reverseArray(arr, 0 , 3);   
    printArray(arr ,4);

    return 0;
}