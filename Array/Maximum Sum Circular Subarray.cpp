#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int maxSum(vector<int> &nums)
    {
        int sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            maxi = max(maxi, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }

public:
    int maxSubarraySumCircular(vector<int> &nums)
    {

        int normalans = maxSum(nums);
        int sum = 0;
        if (normalans < 0)
            return normalans;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            nums[i] = -nums[i];
        }
        int circulaans = maxSum(nums);
        int circular = circulaans + sum;

        int finalans = max(circular, normalans);

        return finalans;
    }
};

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).


/*
class Solution {
private:
    int kadaneMaxSum(int arr[], int n) {
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            maxi = max(sum, maxi);
            if(sum < 0) sum = 0;
        }
        return maxi;
    }

public:
    int circularSubarraySum(int arr[], int num) {
        int nonCircularSum = kadaneMaxSum(arr, num);
        int totalSum = 0;
        for(int i=0; i<num; i++){
            totalSum += arr[i];
            arr[i] = -arr[i];
        }

        int circularSum = totalSum + kadaneMaxSum(arr, num);
        if(circularSum == 0)
            return nonCircularSum;
        return max(circularSum,nonCircularSum);
    }
};
 */