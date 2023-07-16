

#include <bits/stdc++.h>
using namespace std;

// BF
// Multiply i  ->  n times
long long func(int i, int n)
{
    long long ans = 1;
    long long base = i ;
    for (int j = 0; j < n; j++)
    {
        ans *= base;
    }
    return ans;
}

int NthRoot(int n, int m)
{
    // Use linear search on the answer space:
    for (int i = 1; i <= m; i++)
    {
        long long val = func(i, n);
        if (val == m * 1ll)
            return i;
        else if (val > m * 1ll)
            break;
    }
    return -1;
}

// OS
// 1 if ans = m , 2 if ans > m , o if < m
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 3, m = 27;
    int ans = NthRoot(n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
