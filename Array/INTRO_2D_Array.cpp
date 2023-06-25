

#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int arr[rows][cols];
    cout << "Enter the elements of the array:" << endl;
    // row-wise
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
    /* //column-wise
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[j][i];
        }
    } */

    /* cout << "The elements of the array are:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    } */

    // int arr[3][4]= {1,2,3,4,5,6,7,8,9.10,11,12}

    // int arr[3][4]= { {1,1,1,1} , {2,2,2,2} , {3,3,3,3} }










    return 0;
}
