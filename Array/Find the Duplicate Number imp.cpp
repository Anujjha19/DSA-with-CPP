#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    int fast = nums[0];
    int slow = nums[0];
    do
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (slow != fast);

    fast = nums[0];
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }

    return fast;
}

int main()
{
    vector<int> arr = {1, 2, 4, 4, 5, 8, 7, 8, 9, 10, 5};
    int duplicates = findDuplicate(arr);
    cout << "The duplicate elements in the array are: " << duplicates << endl;
    return 0;
}