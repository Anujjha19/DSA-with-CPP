/* Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum)
    {
        if (ind == n)
        {
            ans.push_back(sum);
            return;
        }
        // element is picked
        subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
        // element is not picked
        subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int> ans;
        subsetSumsHelper(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<int> arr{3, 1, 2};
    Solution ob;
    vector<int> ans = ob.subsetSums(arr, arr.size());
    
    sort(ans.begin(), ans.end());
    
    cout << "The sum of each subset is " << endl;
    for (auto sum : ans)
    {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}