#include <bits/stdc++.h>
using namespace std;

int findUnique(int arr[], int size)
{
    int ue = 0 ;
    for ( int i = 0 ; i < size ; i++){
        ue = ue ^ arr[i]; 
    }
    return ue;

}

void print( int arr[] , int n ){
    for(int i =0 ; i< n ; i++ ){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
int main()
{
    int arr[5] = {1, 1, 3, 4 , 4};

    int ue = findUnique( arr , 5 );
    cout << " Unique Element " << ue << endl ;
   
    return 0 ;
}