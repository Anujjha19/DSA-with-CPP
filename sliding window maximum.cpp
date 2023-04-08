#include <iostream>
#include <deque>

#include <vector>

using namespace std;

vector<int> printKMax(int arr[], int n, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {

        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_back();
        }

        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_front();
        }

        dq.push_back(i);
        if (i >= k - 1)
        {
            ans.push_back(arr[dq.front()]);
        }
    }

    return ans;
}

int main()
{
    // int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int arr[] = {c};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    vector<int> v = printKMax(arr, n, k);

    for (auto it : v)
    {
        cout << it << " " << endl;
    }

    return 0;
}
