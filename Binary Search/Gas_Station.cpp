#include <bits/stdc++.h>
using namespace std;
// BF
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    for (int gasStation = 1; gasStation <= k; gasStation++)
    {
        long double maxSection = -1;
        int maxInd = -1;

        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

// OS
typedef long double ld;
double findSmallestMaxDist(vector<int> &arr, int k)
{
    // Code here
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    priority_queue<pair<ld, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int gasStation = 1; gasStation <= k; gasStation++)
    {
        auto topppp = pq.top();
        pq.pop();
        int idx = topppp.second;
        howMany[idx]++;
        ld initalDiff = ld(arr[idx + 1]) - ld(arr[idx]);
        ld newSectionLen = (howMany[idx] == 0) ? initalDiff : initalDiff / ld(howMany[idx] + 1);
        pq.push({newSectionLen, idx});
    }
    return pq.top().first;
}

// OS BS

int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) / dist == numberInBetween)
        {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 6;
    int n = 7;

    long double result = minimiseMaxDistance(arr, k);

    std::cout << "The maximum section length after minimizing the maximum distance is: " << result << std::endl;

    return 0;
}
