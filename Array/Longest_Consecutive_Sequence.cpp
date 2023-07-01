#include <bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}
int Longest_Consec_Seq_B(int arr[], int n)
{
    int logest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int cnt = 1;
        while (linearSearch(arr, n, x + 1) == true)
        {
            x = x + 1;
            cnt++;
        }
        logest = max(logest, cnt);
    }
    return logest;
}

int Longest_Consec_Seq(int arr[], int n)
{

    if (n == 0)
    {
        return 0;
    }

    sort(arr, arr + n);
    int longest = 1;
    int currCount = 0;
    int lastSmallest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastSmallest)
        {
            currCount += 1;
            lastSmallest = arr[i];
        }
        /* else if (arr[i] == lastSmallest)
        {
            continue;
        } */
        else
        { // arr[i] != lastSmallest
            currCount = 1;
            lastSmallest = arr[i];
        }

        longest = max(longest, currCount);
    }
    return longest;
}

int longestSuccessiveElements(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    if (n == 0)
    {
        return 0;
    }

    int longest = 1;
    unordered_set<int> st;
    for (const auto &num : a)
    {
        st.insert(num);
    }

    for (const auto &num : st)
    {
        if (st.find(num - 1) == st.end())
        {
            int cnt = 1;
            int x = num;

            while (st.find(x + 1) != st.end())
            {

                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main()
{

    // Array Initialization.
    int n = 10;
    int arr[n] = {5, 3, 5, 2, 100, 4, 101, 103, 5, 110};

    int ans = Longest_Consec_Seq(arr, n);
    cout << "Longest Consecutive Sequence:  " << ans << endl;
    cout << endl;
    return 0;
}
