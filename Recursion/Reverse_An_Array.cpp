

#include <iostream>
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

/* void Reverse_1_Pointer(int arr[], int n)
{
    int i = 0;
    while (i <= n / 2)
    {
        swap(arr[i], arr[n - i - 1]);
        i++;
    }
} */
void Reverse_1_Pointer(int i, int arr[], int n)
{
    
    if (i >= n / 2) return;
        swap(arr[i], arr[n - i - 1]);
        
    Reverse_1_Pointer( i+1,  arr , n);
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
    //Reverse_1_Pointer(arr, n);
    Reverse_1_Pointer(0, arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    
}
