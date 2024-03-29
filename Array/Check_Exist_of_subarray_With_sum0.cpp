
#include <bits/stdc++.h>
using namespace std;

bool subArrayExistss(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = arr[i];
        if (sum == 0)
            return true;
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
                return true;
        }
    }
    return false;
}

bool subArrayExists(int arr[], int n)
{
    // Your code here

    unordered_set<int> st;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0 || st.find(sum) != st.end())
        {
            return true;
        }
        st.insert(sum);
    }
    return false;
}

int main()
{
    int arr[] = {-3, 2, 3, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);

    if (subArrayExists(arr, N))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}
