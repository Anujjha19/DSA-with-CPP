#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void moveZeroes(int arr[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    int i, arr_size = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, arr_size);

    cout << "Array after Moving all Zeros at END is ";
    for (i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}

/* #include<bits/stdc++.h>
using namespace std;

void zerosToEnd(int arr[],int n) {

        int temp[n];
        int k=0;
        for (int i=0;i<n;i++){
            if (arr[i]!=0){
                temp[k]=arr[i];
                k++;
            }
        }

        while (k<n){
            temp[k]=0;
            k++;
        }
        for(int i=0;i<n;i++)
        {
            cout<<temp[i]<<" ";
        }
    }

int main() {
      int arr[] ={ 1,2,0,1,0,4,0};
       zerosToEnd(arr,7);
}

 */