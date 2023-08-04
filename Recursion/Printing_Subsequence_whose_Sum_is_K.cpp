#include <iostream>
#include <vector>

using namespace std;

// All subsequence
void findSubsequences(vector<int> &nums, int k, vector<int> &current, int index, int sum)
{
    if (sum == k)
    {
        for (int num : current)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    if (index >= nums.size() || sum > k)
    {
        return;
    }
    current.push_back(nums[index]);
    findSubsequences(nums, k, current, index + 1, sum + nums[index]);

    // Exclude the current element from the subsequence
    current.pop_back();
    findSubsequences(nums, k, current, index + 1, sum);
}

// Only 1 subsequence
bool findSubsequences_ONLY_1(vector<int> &nums, int k, vector<int> &current, int index, int sum)
{
    if (index == nums.size())
    {
        if (sum == k)
        {
            for (int num : current)
            {
                cout << num << " ";
            }
            cout << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    current.push_back(nums[index]);
    if (findSubsequences_ONLY_1(nums, k, current, index + 1, sum + nums[index]) == true)
    {
        return true;
    }

    // Exclude the current element from the subsequence
    current.pop_back();
    if (findSubsequences_ONLY_1(nums, k, current, index + 1, sum) == true)
    {
        return true;
    }

    return false;
}

void findAllSubsequencesWithSumK(vector<int> &nums, int k)
{
    vector<int> current;
    findSubsequences(nums, k, current, 0, 0);

    findSubsequences_ONLY_1(nums, k, current, 0, 0);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 7;

    findAllSubsequencesWithSumK(nums, k);

    return 0;
}
