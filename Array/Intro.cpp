#include <iostream>
using namespace std;
int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    // Printing Array
    cout << arr[2] << endl;
    for (int k = 0; k < 5; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
    // Taking From User
    int n;
    cout << "N"
                 << "- ";
    cin >> n;
    int brr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    cout << "the Brr array is : ";
    for (int j = 0; j < n; j++)
    {
        cout << brr[j] << "  ";
    }

    int sum = 0;
    int avg = 0;
    int size = sizeof(brr) / sizeof(int);
    for (int j = 0; j < n; j++)
    {
        sum += brr[j];
        avg = sum / size;
    }
    cout << "Sum is " << sum << endl;
    cout << "Avg  is " << avg << endl;

    int k;
    int x;
    cout << "enter element to be inserted At END : ";
    cin >> x;
    arr[5] = x;
    cout << " End element inserted " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}