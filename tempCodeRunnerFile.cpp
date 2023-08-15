#include <iostream>
#include <vector>

using namespace std;

// Function to check if the current cell is valid or not
bool isValidCell(int x, int y, int n, vector<vector<int>>& maze) {
    // Check if the cell is within the maze boundaries and is not blocked (0)
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] != 0);
}

// Recursive function to find a path from start to destination in the maze
bool findPath(int x, int y, int n, vector<vector<int>>& maze, vector<vector<int>>& path) {
    // If the current cell is the destination, return true
    if (x == n - 1 && y == n - 1) {
        path[x][y] = 1;
        return true;
    }

    // Check if the current cell is valid
    if (isValidCell(x, y, n, maze)) {
        // Mark the current cell as part of the path
        path[x][y] = 1;

        // Move right
        if (findPath(x, y + 1, n, maze, path))
            return true;

        // Move down
        if (findPath(x + 1, y, n, maze, path))
            return true;

        // If no path is found, backtrack by marking the current cell as not part of the path
        path[x][y] = 0;
    }

    return false;
}

// Function to solve the Rat in a Maze problem
void solveMaze(vector<vector<int>>& maze) {
    int n = maze.size();

    // Create a path matrix to store the path
    vector<vector<int>> path(n, vector<int>(n, 0));

    // Find a path from (0, 0) to (n-1, n-1)
    if (findPath(0, 0, n, maze, path)) {
        cout << "Path found:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found." << endl;
    }
}

int main() {
    // Example maze
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}