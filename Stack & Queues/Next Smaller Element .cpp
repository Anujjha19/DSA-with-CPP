#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> s;
        int n = nums.size();

        vector<int> nge(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--)
        {

            while (!s.empty() && s.top() >= nums[i % n])
            {
                s.pop();
            }

            if (i < n)
            {
                if (!s.empty())
                    nge[i] = s.top();
            }
            s.push(nums[i % n]);
        }
        return nge;
    }
};
int main()
{
    Solution obj;
    vector<int> v{5, 7, 1, 2, 6, 0};
    vector<int> res = obj.nextGreaterElements(v);
    cout << "The next greater elements are" << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}
/* 
vector<int> NSE(vector<int> &arr, int n)
{

    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];

        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr)''
    }

    return ans;
} */    