#include <iostream>
#include <vector>
using namespace std;


    bool searchMatrix(vector<vector<int>>& matrix, int target) { 
        
        int row= matrix.size();
        int col = matrix[0].size();
        int rowIndex=0;
        int colIndex= col-1;
        while(rowIndex< row && colIndex >= 0){
            int element = matrix[rowIndex][colIndex];
            if(element== target){
                return 1;
                
            }
            if (element < target){
                rowIndex++;
            }
            else{
                // element > target
                colIndex--;
            }
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

    cout << "Element is present or not " << endl;
    cout << searchMatrix(arr , 8 );

    return 0;
}
