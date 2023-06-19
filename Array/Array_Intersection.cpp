#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void ArrayIntersection(int arr[], int brr[], int size)
{
    int crr[size];
    int k = 0;

    int i = 0, j = 0;
    while (i < size && j < size)
    {
        if (arr[i] == brr[j])
        {
            crr[k++] = arr[i];
            i++;
            j++;
        }
        else if (arr[i] > brr[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    print(crr, k);
}

int main()
{
    int n = 4;
    int a1[4] = {1, 2, 3, 4};
    int a2[4] = {1, 2, 3, 6};

    ArrayIntersection(a1, a2, n);

    return 0;
}
