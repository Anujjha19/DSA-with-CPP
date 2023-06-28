#include<iostream>
#include<vector>
using namespace std;

void wavePrint(vector<vector<int> > arr, int nRows, int mCols)
{
    // Iterate over the columns
    for (int j = 0; j < mCols; j++)
    {
        // If the column is even, print from top to bottom
        if (j % 2 == 0)
        {
            for (int i = 0; i < nRows; i++)
            {
                cout << arr[i][j] << " ";
            }
        }
        // If the column is odd, print from bottom to top
        else
        {
            for (int i = nRows - 1; i >= 0; i--)
            {
                cout << arr[i][j] << " ";
            }
        }
    }
}

int main() {
    
    // Declare and initialize a 2D vector
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};

    cout << "The elements of the array are:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Wave print of the array is:" << endl;
    wavePrint(arr, 3, 3);

    return 0;
}
