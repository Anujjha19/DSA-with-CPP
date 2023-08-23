#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
int solveRM(long long n, vector<int> &dp)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return 1;
    }
    // Handling overlapping subproblems
    if (dp[n] != -1)
        return dp[n] % mod;
    return dp[n] = (solveRM(n - 1, dp) + solveRM(n - 2, dp)) % mod;
}

int tabulationSol(long long n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    return dp[n] % mod;
}
int countDistinctWays(long long n)
{
    vector<int> dp(n + 1, -1);
    // return solveRM(n,dp);
    return tabulationSol(n);
}

int main()
{

    int n = 3;
    vector<int> dp(n + 1, -1);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}
