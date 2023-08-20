#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> matrixxx, int target)
{
    int s = 0;
    int e = matrixxx.size() - 1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (matrixxx[mid] == target)
        {
            return true;
        }
        else if (matrixxx[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][0] <= target && target <= mat[i][mat.size() - 1])
        {
            return binarySearch(mat[i], target);
        }
    }

    return false;
}

// BS Optiml
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = (m * n) - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

int main()
{
    // Create a sample matrix
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target = 16;

    bool found = searchMatrix(matrix, target);

    if (found)
    {
        cout << "Target found in the matrix." << endl;
    }
    else
    {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
