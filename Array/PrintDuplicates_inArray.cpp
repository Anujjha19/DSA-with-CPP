#include <iostream>
#include <vector>

using namespace std;

void findRepeatingElements(vector<int> &arr)
{
    vector<bool> visited(arr.size(), false); // initialize visited array with false

    cout << "Repeating elements: ";
    for (int i = 0; i < arr.size(); i++)
    {
        if (visited[arr[i]])
        { // if element is already visited, it is a repeating element
            cout << arr[i] << " ";
        }
        else
        {
            visited[arr[i]] = true; // mark element as visited
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 4, 4, 5, 9, 10, 5};
    findRepeatingElements(arr);
    return 0;
}
/* 
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {

        vector<bool> visited(nums.size(), false);
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[nums[i]])
            {

                ans.push_back(nums[i]);
            }
            else
            {
                visited[nums[i]] = true;
            }
        }
        return ans;
    }
}; */