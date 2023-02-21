#include <iostream>
using namespace std;

void countSort(int arr[], int n, int k) {
    //Max Size Array
    int count[k+1];
    for(int i=0; i<=k; i++) {
        count[i] = 0;
    }
    //Count each Element
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }
    //Position - add before + current
    for(int i=1; i<=k; i++) {
        count[i] += count[i-1];
    }
    //Temp Array
    
    int output[n];
    for(int i=n-1; i>=0; i--) {
        output[count[arr[i]]  -  1 ] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0; i<n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    //Max Element
    int k = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > k) {
            k = arr[i];
        }
    }
    countSort(arr, n, k);
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
