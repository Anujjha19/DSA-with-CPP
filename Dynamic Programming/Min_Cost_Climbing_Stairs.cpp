#include <iostream>
#include <vector>
using namespace std;

// TLE R
int solveR(vector<int> &cost, int n)
{
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];
    int a = cost[n] + min(solveR(cost, n - 1), solveR(cost, n - 2));
    return a;
}
int minCostClimbingStairs__R(vector<int> &cost)
{
    int n = cost.size();
    int ans = min(solveR(cost, n - 1), solveR(cost, n - 2));

    return ans;
}

// Memo DP
int solve_MDP(vector<int> &cost, int n, vector<int> &dp)
{
    if (n == 0)
        return cost[0];
    if (n == 1)
        return cost[1];
    if (dp[n] != -1)
        return dp[n];
    dp[n] = cost[n] + min(solve_MDP(cost, n - 1, dp), solve_MDP(cost, n - 2, dp));
    return dp[n];
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);

    int ans = min(solve_MDP(cost, n - 1, dp), solve_MDP(cost, n - 2, dp));

    return ans;
}

// Tabulation Unoptimized Solution
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; i++)
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    return min(dp[n - 1], dp[n - 2]);
}

// Tabulation Optimized Solution
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    int prev1 = cost[0];
    int prev2 = cost[1];
    int curr = 0;
    for (int i = 2; i < n; i++)
    {
        curr = min(prev1, prev2) + cost[i];
        prev1 = prev2;
        prev2 = curr;
    }
    return min(prev1, prev2);
}

int main()
{
    vector<int> cost = {10, 15, 20};

    int result = minCostClimbingStairs(cost);

    cout << "Minimum cost: " << result << endl;

    return 0;
}
