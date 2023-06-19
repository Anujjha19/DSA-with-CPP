#include <bits/stdc++.h>
using namespace std;

void swapAlternative(int arr[], int size)
{
    // Write your code here
    for (int i = 0; i < size; i += 2)
    {
        if ((i + 1) < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void print( int arr[] , int n ){
    for(int i =0 ; i< n ; i++ ){
        cout << arr[i] <<" ";
    }
    cout << endl;
}
int main()
{
    int even[4] = {1, 2, 3, 4};
    int odd[5] = {1, 2, 3, 4, 5};

    swapAlternative(even, 4);
    print(even , 4);
    cout << endl ;
    swapAlternative(odd, 5);
    print( odd , 5);

    return 0 ;
}