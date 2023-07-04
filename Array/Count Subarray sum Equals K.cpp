
#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum_Brute(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    int cnt = 0;        // Number of subarrays:

    for (int i = 0; i < n; i++)
    { // starting index i
        for (int j = i; j < n; j++)
        { // ending index j

            // calculate the sum of subarray [i...j]
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int findAllSubarraysWithGivenSum_Better(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    int cnt = 0;        // Number of subarrays:

    for (int i = 0; i < n; i++)
    { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++)
        { // ending index j
            // calculate the sum of subarray [i...j]
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            // Increase the count if sum == k:
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the given array.
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++)
    {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarraysWithGivenSum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}
