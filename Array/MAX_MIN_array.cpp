#include<iostream>
using namespace std;

int getMin(int num[], int size) {
    int n=size;
    int mini = num[0];
    for(int i = 0; i<n; i++) {
        mini = min( mini, num[i]);
    }
    //returning min value
    return mini;
}

int getMax(int num[], int n) {
    int max = INT16_MIN;
    for(int i = 0; i<n; i++) {
       // max = max(max, num[i]);
        if(num[i] > max){
            max = num[i];
        }
    }
    //returning max value
    return max;
}

int main() {
    int size;
    cin >> size;
    int num[100];
    //taking input in array
    for(int i = 0; i<size; i++) {
        cin >> num[i];
    }
    cout << " Maximum value is " << getMax(num, size) << endl;
    cout << " Minimum value is " << getMin(num, size) << endl;
    return 0;
}
//Time Complexity: O(N)
