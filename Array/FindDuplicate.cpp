/* #include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }

    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ i;
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 6, 7, 8, 9, 10, 5};
    int duplicate = findDuplicate(arr);
    cout << "The duplicate element in the array is: " << duplicate << endl;
    return 0;
}
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findDuplicates(vector<int>& arr) {
    unordered_map<int, int> freq;
    vector<int> duplicates;
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }
    for (auto it : freq) {
        if (it.second > 1) {
            duplicates.push_back(it.first);
        }
    }
    return duplicates;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 5, 8, 7, 8, 9, 10, 5};
    vector<int> duplicates = findDuplicates(arr);
    cout << "The duplicate elements in the array are: ";
    for (int i = 0; i < duplicates.size(); i++) {
        cout << duplicates[i] << " ";
    }
    cout << endl;
    return 0;
}
