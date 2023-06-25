#include <iostream>
using namespace std;

bool search_ISpresent(int arr[][3], int n, int target)
{
    // Search for the target element in the 2D array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// to print row wise sum
void row_Wise_sum(int arr[][3], int row, int col)
{
    cout << "Printing Sum -> ";
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

// to print Column wise sum
void column_Wise_sum(int arr[][3], int row, int col)
{
    cout << "Printing Sum -> " << endl;
    for (int col = 0; col < 3; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}

void LargestRowSum_InWhichh_Row(int arr[][3], int row, int col)
{
    int maxi = INT16_MIN;
    int rowIndex = -1;

    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = row;
        }
    }
    cout << "Maximum Row Sum : " << maxi << " , At Row No : " << rowIndex << endl;
    ;
}




int main()
{
    int n = 3;
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "The elements of the array are:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int target = 7;
    cout << "Search in a 2-D array " << endl;
    if (search_ISpresent(arr, n, target))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    // row wise addition

    cout << endl;
    row_Wise_sum(arr, n, n);
    cout << endl;
    column_Wise_sum(arr, n, n);

    cout << endl;
    LargestRowSum_InWhichh_Row(arr, n, n);

    return 0;
}
