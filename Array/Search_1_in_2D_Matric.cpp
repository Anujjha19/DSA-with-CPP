#include <iostream>
#include <vector>
using namespace std;


    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row * col - 1;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            int element = matrix[mid / col][mid % col];
            if (element == target)
            {
                return 1;
            }
            if (element < target)
            {
                start = mid + 1;
            }
            if (element > target)
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return 0;
    }


int main()
{

    // Declare and initialize a 2D vector
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << "The elements of the array are:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Spiral print of the array is:" << endl;
    cout << searchMatrix(arr , 8 );

    return 0;
}
