#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k, int &res)
{
    // code here
    sort(arr, arr + n);

    int firstMax = arr[n - 1];
    int firstMin = arr[0];
    res = firstMax - firstMin;

    int s = arr[0] + k;
    int e = arr[n - 1] - k;

    int maxV = INT_MIN;
    int minV = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        maxV = max(e, arr[i - 1] + k);
        minV = min(s, arr[i] - k);

        res = min(res, (maxV - minV));
    }
    return res;
}

int main()
{
    int arr[] = {1, 5, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int res = 0;
    int ans = getMinDiff(arr, n, k, res);
    cout << ans;
    return 0;
}