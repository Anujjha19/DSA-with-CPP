/* Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair. At a time the frog can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from a stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1.
 */
#include <bits/stdc++.h>
using namespace std;

int solve_Recursive(int index, vector<int> &arr)
{
    if (index == 0)
        return 0;
    int left = solve_Recursive(index - 1, arr) + abs(arr[index - 1] - arr[index]);
    int right = INT_MAX;
    if (index > 1)
    {
        right = solve_Recursive(index - 2, arr) + abs(arr[index - 2] - arr[index]);
    }

    int ans = min(left, right);
    return ans;
}
int frogJump(int n, vector<int> &heights)
{
    int ans = solve_Recursive(n - 1, heights);
    return ans;
}

int solve_Memoization(int index, vector<int> &arr, vector<int> &dp)
{
    if (index == 0)
        return 0;
    if (dp[index] != -1)
        return dp[index];
    int left = solve_Memoization(index - 1, arr, dp) + abs(arr[index - 1] - arr[index]);
    int right = INT_MAX;
    if (index > 1)
    {
        right = solve_Memoization(index - 2, arr, dp) + abs(arr[index - 2] - arr[index]);
    }
    dp[index] = min(left, right);
    return dp[index];
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    int ans = solve_Memoization(n - 1, heights, dp);
    return ans;
}

int frogJump_Tabulation(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int leftFS = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int rightSS = INT_MAX;
        if (i > 1)
        {
            rightSS = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(leftFS, rightSS);
    }
    return dp[n - 1];
}

int frogJump_Space_Optimisation(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int leftFS = prev1 + abs(heights[i] - heights[i - 1]);
        int rightSS = INT_MAX;
        if (i > 1)
        {
            rightSS = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curr = min(leftFS, rightSS);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}


int main()
{
    int n = 4;

    vector<int> v{10, 20, 30, 10};
    int ans = frogJump(4, v);

    cout << "Main" << ans;

    return 0;
}