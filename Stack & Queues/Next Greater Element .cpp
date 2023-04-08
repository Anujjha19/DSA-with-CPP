#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    /* void printNGE(int arr[], int n)
    {
        int next, i, j;
        for (i = 0; i < n; i++) {
            next = -1;
            for (j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    next = arr[j];
                    break;
                }
            }
            cout << arr[i] << " --> " << next << endl;
        }
    } */

    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> s;
        int n = nums.size();

        vector<int> nge(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--)
        {

            while (!s.empty() && s.top() <= nums[i % n])
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
class Solution {
public:

 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>umap;
        stack<int>st;
        int n = nums2.size();

        for(int i=n-1; i>=0; i--){
            int ele = nums2[i];
            while(!st.empty() && st.top() <= ele){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            umap.insert({ele, res});
            st.push(ele);
        }

        vector<int> ans;
        for(auto x: nums1){
            ans.push_back(umap[x]);
        }

        return ans;
    }

};
 */