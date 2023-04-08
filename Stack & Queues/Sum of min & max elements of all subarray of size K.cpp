





#include <bits/stdc++.h>
using namespace std;

int sumMaxMinInWindowSize(int *arr, int n, int k)
{
    deque<int> maxi;
    deque<int> mini;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }
    
    sum += arr[maxi.front()] + arr[mini.front()];

    for (int i = k; i < n; i++)
    
    {
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        sum += arr[maxi.front()] + arr[mini.front()];
    }

    return sum;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};

    int n = 7, k = 4;
    cout << sumMaxMinInWindowSize(arr, n, k) << endl;

    return 0;
}













/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> ansmain;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0; // Initialize the answer
    int mainAns = 0;
    for (int i = 0; i <= n - k; i++)
    {                                               // Loop through all possible subarrays of size K
        int curr_min = INT_MAX, curr_max = INT_MIN; // Initialize current min and max
        for (int j = i; j < i + k; j++)
        { // Loop through elements in the subarray
            curr_min = min(curr_min, arr[j]);
            curr_max = max(curr_max, arr[j]);
        }
        mainAns = curr_min + curr_max;
        ans += curr_min + curr_max; // Add current min and max to the answer
        ansmain.push_back(mainAns);
        cout << "Max element of subarray starting at index " << i << ": " << curr_max << endl;
        cout << "Min element of subarray starting at index " << i << ": " << curr_min << endl;
    }
    cout << "Sum of min and max elements of all subarrays of size " << k << ": " << ans << endl;

    for (auto it : ansmain)
    {
        cout << it << " ";
    }

    return 0;
} */









/* #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> ansmain;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int mainAns = 0;
    for (int i = 0; i <= n - k; i++)
    {                                               // Loop through all possible subarrays of size K
        int curr_min = INT_MAX, curr_max = INT_MIN; // Initialize current min and max
        for (int j = i; j < i + k; j++)
        { // Loop through elements in the subarray
            curr_min = min(curr_min, arr[j]);
            curr_max = max(curr_max, arr[j]);
        }
        mainAns = curr_min + curr_max;
        ansmain.push_back(mainAns);
        // cout << "Max element of subarray starting at index " << i << ": " << curr_max << endl;
        // cout << "Min element of subarray starting at index " << i << ": " << curr_min << endl;
    }
    cout << "Sum of min and max elements of all subarrays of size " << k << ": " << 

    for (auto it : ansmain)
    {
        cout << it << " ";
    }
    
     << endl;

    
    return 0;
}  */