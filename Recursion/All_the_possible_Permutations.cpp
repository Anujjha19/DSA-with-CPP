#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permuteHelper(vector<int> &nums, int index, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int j = index; j < nums.size(); j++)
    {
        swap(nums[index], nums[j]);
        permuteHelper(nums, index + 1, result);

        // Backtrack to its original position
        
        swap(nums[index], nums[j]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    // Print the permutations
    for (const auto &permutation : permutations)
    {
        for (const auto &num : permutation)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

//2 
/* void generatePermutations(std::string str) {
    // Sort the string in lexicographically increasing order
    sort(str.begin(), str.end());

    // Print the first permutation
    cout << str << endl;

    // Generate and print the rest of the permutations
    while (next_permutation(str.begin(), str.end())) {
        cout << str << endl;
    }
}

int main() {
    string str = "abc";
    generatePermutations(str);
    return 0;
} */