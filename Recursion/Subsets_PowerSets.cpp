#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> &nums, int index, vector<int> &output, vector<vector<int>> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }
    // Exclude
    solve(nums, index + 1, output, ans);
    // Add element
    int ele = nums[index];
    output.push_back(ele);
    // include
    solve(nums, index + 1, output, ans);
    output.pop_back(); // Restore output vector
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(nums, index, output, ans);

    return ans;
}

int main()
{
    vector<int> nums = {3, 1, 2};

    // Print all the subsets
    cout << "Subsets are:" << endl;
    vector<vector<int>> ans = subsets(nums);

    for (auto it : ans)
    {
        for (auto num : it)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
