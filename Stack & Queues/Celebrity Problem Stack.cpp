#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, vector<vector<int>> &M, int n)
{
    if (M[a][b] == 1)
        return true;
    else
        return false;
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(a, b, M, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int candidate = s.top();
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
            zeroCount++;
    }
    if (zeroCount != n)
        return -1;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
            oneCount++;
    }
    if (oneCount != n - 1)
        return -1;

    return candidate;
}

/*
    int candidate = s.top();

    bool RowCheck = false;
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
            zeroCount++;
    }
    if (zeroCount == n)
        RowCheck = true;

    bool ColCheck = false;
    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
            oneCount++;
    }
    if (oneCount == n - 1)
        ColCheck = true;

    if (RowCheck == true && ColCheck == true)
        return candidate;
    else
        return -1;
}
 */

int main()
{
    int n = 3;
    vector<vector<int>> M(n, vector<int>(n));

    M[0][0] = 0;
    M[0][1] = 1;
    M[0][2] = 0;
    M[1][0] = 0;
    M[1][1] = 0;
    M[1][2] = 0;
    M[2][0] = 0;
    M[2][1] = 1;
    M[2][2] = 0;

    // M = {{0, 1}, {1, 0}};

    int result = celebrity(M, n);
    if (result == -1)
        printf("No celebrity");
    else
        printf("Celebrity ID is %d", result);

    return 0;
}
