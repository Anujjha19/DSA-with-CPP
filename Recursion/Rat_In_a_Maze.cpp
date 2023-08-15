#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<int>> &visited, vector<vector<int>> &maze, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (visited[newx][newy] == 0) && (maze[newx][newy] == 1))
    {
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &maze, int n, vector<string> &ans, vector<vector<int>> visited, string path, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;

    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, visited, maze, n))
    {
        path.push_back('D');
        solve(maze, n, ans, visited, path, newx, newy);
        path.pop_back();
    }
    // Up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, visited, maze, n))
    {
        path.push_back('U');
        solve(maze, n, ans, visited, path, newx, newy);
        path.pop_back();
    }
    // Left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, visited, maze, n))
    {
        path.push_back('L');
        solve(maze, n, ans, visited, path, newx, newy);
        path.pop_back();
    }
    // Down
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, visited, maze, n))
    {
        path.push_back('R');
        solve(maze, n, ans, visited, path, newx, newy);
        path.pop_back();
    }


        visited[x][y] = 0;
        
}

vector<string> findPath(vector<vector<int>> &maze, int n)
{
    vector<string> ans;
    if (maze[0][0] == 0)
    {
        return ans;
    }
    vector<vector<int>> visited = maze;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    int srcx = 0, srcy = 0;
    string path = "";

    solve(maze, n, ans, visited, path, srcx, srcy);
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n = 4;

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};

    vector<string> result = findPath(maze, n);
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
