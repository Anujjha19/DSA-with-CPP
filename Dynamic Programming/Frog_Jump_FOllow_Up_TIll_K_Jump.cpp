#include <bits/stdc++.h>
using namespace std;

// Recursion
int FindFrog_k_jump_R(int ind, int K, vector<int> &height)
{
    if (ind == 0)
        return 0;
    int minSteps = INT_MAX;
    for (int j = 1; j <= K; j++)
    {
        if (ind - j >= 0)
        {
            int jump = FindFrog_k_jump_R(ind - j, K, height) + abs(height[ind] - height[ind - j]);
            minSteps = min(jump, minSteps);
        }
    }
    return minSteps;
}

// Memoization
int solveUtil(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int mmSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (ind - j >= 0)
        {
            int jump = solveUtil(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            mmSteps = min(jump, mmSteps);
        }
    }
    return dp[ind] = mmSteps;
}
int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return solveUtil(n - 1, height, dp, k);
}

// Tabulation
int solveUtil(int n, vector<int> &height, vector<int> &dp, int k)
{
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int mmSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(height[i] - height[i - j]);
                mmSteps = min(jump, mmSteps);
            }
        }
        dp[i] = mmSteps;
    }
    return dp[n - 1];
}
int solve(int n, vector<int> &height, int k)
{
    vector<int> dp(n, -1);
    return solveUtil(n, height, dp, k);
}


int main()
{
    int n = 5;
    int k = 3;

    vector<int> height{10, 30, 40, 50, 20};

    int result = FindFrog_k_jump_R(n - 1, k, height);
    cout << "Minimum number of steps: " << result << endl;

    return 0;
}
