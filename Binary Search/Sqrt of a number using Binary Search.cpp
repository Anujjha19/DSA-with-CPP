

#include <bits/stdc++.h>
using namespace std;

// BF   ->   LS
int floorSqrt(int n)
{
    int ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        long long val = i * i;
        if (val <= n * 1ll)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

// OA
int floorSqrt(int n)
{
    int ans = sqrt(n);
    return ans;
}

// OA
int floorSqrt(int n)
{
    int low = 1, high = n;
    // Binary search on the answers:
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n))
        {
            // eliminate the left half:
            low = mid + 1;
        }
        else
        {
            // eliminate the right half:
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}
