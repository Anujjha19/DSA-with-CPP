#include <iostream>
using namespace std;
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    // Base Case
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}
// Sorting  TC - O( n logn)
int main()
{
    int arr[5] = {5, 10, 8, 45, 1};
    printArray(arr, 5);
    int k = 2;
    bubbleSort(arr, 5);
    printArray(arr, 5);
    cout << "ans " << arr[k - 1] << endl;

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}