/* Problem Statement
You have been given a non-empty grid 'mat' with 'n' rows and 'm'columns consisting of only Os and Is. All the rows are sorted in ascending order.
Your task is to find the index of the row with the maximum number of ones.
Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1. */

#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxOnes = 0;
    int rowIndex = -1;

    for (int i = 0; i < n; i++)
    {
        int onesCount = 0;
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                onesCount++;
            }
        }

        if (onesCount > maxOnes)
        {
            maxOnes = onesCount;
            rowIndex = i;
        }
    }   
    return rowIndex;
    /*
    if (rowIndex == -1){
    return {0, 0};
    }
    else
    {
    return {rowIndex, maxOnes};
    } */
}

int main()
{
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the elements of the matrix (0s and 1s):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int result = rowWithMax1s(matrix, n, m);
    if (result == -1)
    {
        cout << "No row with at least 1 zero found." << endl;
    }
    else
    {
        cout << "Row with maximum number of ones: " << result << endl;
    }
    return 0;
}
