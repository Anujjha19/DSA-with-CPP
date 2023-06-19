#include <bits/stdc++.h>
using namespace std;
/* void leftRotate(int arr[], int n, int d) {
    if (n == 0) return;

    // Get the effective number of rotations:
    d = d % n;

    //checking if d is a multiple of n:
    if (d == 0) return;

    int temp[d]; // temporary array

    //step 1: Copying first d elements
    // in the temporary array:
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // step 2: Shift last (n-d) elements
    // to the left by d places in the given array:
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    //step 3: Place the elements of the temporary
    // array in the last d places of the given array:
    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];
    }
}
 */

void leftRotate(int arr[], int n, int d)
{

    if (n == 0)
        return;

    // Get the effective number of rotations:
    d = d % n;

    // step 1:
    reverse(arr, arr + d);

    // step 2:
    reverse(arr + d, arr + n);

    // step 3:
    reverse(arr, arr + n);
}

int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 3;

    cout << "Before rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    leftRotate(arr, n, d);
    cout << "After rotation:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
Output:
