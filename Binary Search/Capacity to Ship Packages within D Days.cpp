#include <bits/stdc++.h>
#include <vector>

using namespace std;

// BF
int noOfDays(vector<int> &weights, int cap)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > cap)
        {
            days = days + 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        sum += weights[i];
    }
    for (int capi = maxi; capi <= sum; capi++)
    {
        int daysRequired = noOfDays(weights, capi);
        if (daysRequired <= d)
            return capi;
    }
    return -1;
}

// OS
class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int d)
    {
        int maxi = *max_element(weights.begin(), weights.end());
        int sum = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
        }
        int low = maxi;
        int high = sum;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);

            if (noOfDays(weights, mid) <= d)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    Solution solution;

    // Example 1
    vector<int> weights1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days1 = 5;
    int result1 = solution.shipWithinDays(weights1, days1);
    cout << "Minimum weight capacity for Example 1: " << result1 << endl;

    // Example 2
    vector<int> weights2 = {3, 2, 2, 4, 1, 4};
    int days2 = 3;
    int result2 = solution.shipWithinDays(weights2, days2);
    cout << "Minimum weight capacity for Example 2: " << result2 << endl;

    return 0;
}
