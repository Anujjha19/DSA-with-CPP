#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        unordered_set<int> unqSet;
        for (int n : arr)
        {
            mp[n]++;
        }
        for (auto it : mp)
        {
            int frequency = it.second;
            unqSet.insert(frequency);
        }
        return mp.size() == unqSet.size();
    }
};

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    Solution sol;
    bool result = sol.uniqueOccurrences(arr);
    if (result)
    {
        cout << "The occurrences of each element in the array are unique." << endl;
    }
    else
    {
        cout << "The occurrences of some elements in the array are not unique." << endl;
    }
    return 0;
}
