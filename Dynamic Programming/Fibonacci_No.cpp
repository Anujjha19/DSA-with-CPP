#include <bits/stdc++.h>
using namespace std;

// Top Down  -> Recursion + Memoization TC : O(n) , SC : O(n) + O(n)
int findFiboNacci_RM(int n, vector<int> &dp)
{
    // int dp[n + 1];
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i] = -1;
    // }
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = findFiboNacci_RM(n - 1, dp) + findFiboNacci_RM(n - 2, dp);
    return dp[n];
}

// Bottom UP  -> Tabulation  TC : O(n) , SC : O(n)
int findFiboNacci_T(int n, vector<int> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[n] = dp[n - 1] + dp[n - 2];
    }
    return dp[n];
}

// Space Optimization TC : O(n) , SC : O(1)
int findFiboNacci_SO(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    int prev1 = 1;
    int prev2 = 0;

    for (int i = 2; i <= n; i++)
    {
        int next = prev1 + prev2;
        prev2 = prev1;
        prev1 = next;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter N : ";
    cin >> n;
    vector<int> dp(n + 1, -1);

    int ansRM = findFiboNacci_RM(n, dp);
    int ansT = findFiboNacci_T(n, dp);
    int ansSO = findFiboNacci_SO(n, dp);

    cout << "Fibonacci of " << n << " is : " << ansRM << endl;
    cout << "Fibonacci of " << n << " is : " << ansT << endl;
    cout << "Fibonacci of " << n << " is : " << ansSO;

    return 0;
}