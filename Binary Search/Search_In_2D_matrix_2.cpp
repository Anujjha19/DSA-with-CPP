/* Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 */

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(const vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    if (n == 0)
    {
        return false;
    }
    int m = matrix[0].size();
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0)
    {
        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 20;

    // Call the searchMatrix function
    bool result = searchMatrix(matrix, target);

    // Print the result
    cout << boolalpha << result << endl;

    return 0;
}
