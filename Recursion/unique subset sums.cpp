#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    void subsetSumsHelper(int ind, vector<int>& arr, int n, vector<int>& ans, int sum) {
        if (ind == n) {
            ans.push_back(sum);
            return;
        }
        // element is picked
        subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
        // element is not picked
        subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }

    vector<int> subsetSums(vector<int>& arr, int n) {
        vector<int> ans;
        subsetSumsHelper(0, arr, n, ans, 0);

        // Create a set and pass the begin and end iterators of the ans vector
        set<int> mySet(ans.begin(), ans.end());

        // Convert the set back to a vector
        vector<int> uniqueSubsetSums(mySet.begin(), mySet.end());

        return uniqueSubsetSums;
    }
};

int main() {
    vector<int> arr{3, 1, 2};
    Solution ob;
    vector<int> ans = ob.subsetSums(arr, arr.size());

    cout << "The sum of each unique subset is:" << endl;
    for (auto sum : ans) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}