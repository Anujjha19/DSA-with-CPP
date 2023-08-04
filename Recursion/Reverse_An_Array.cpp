#include <iostream>
#include <algorithm>
using namespace std;

void Reverse_2_Pointer(int arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        swap(arr[s++], arr[e--]);
    }
}

void Reverse_1_Pointer(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    Reverse_1_Pointer(i + 1, arr, n);
}

void func_2P_recursive(int arr[], int s, int e)
{
    if (s >= e)
        return;
    
    swap(arr[s], arr[e]);
    func_2P_recursive(arr, s + 1, e - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array Is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Reverse_2_Pointer Array Is : ";
    Reverse_2_Pointer(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Reverse_1_Pointer Array Is : ";
    Reverse_1_Pointer(0, arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

//Recursive 
    int brr[5] = {1, 4, 5, 6, 7};
    func_2P_recursive(brr, 0, 4);

    cout << "brr Array Is : ";
    for (int i = 0; i < 5; i++)
    {
        cout << brr[i] << " ";
    }
    cout << endl;

    return 0;
}
