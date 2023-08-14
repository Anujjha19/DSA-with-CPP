#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string removeDuplicates(string str) {
    unordered_map<char, int> mpp;
    for (int i = 0; i < str.length(); i++) {
        mpp.insert(make_pair(str[i], 0));
    }
    string ans = "";
    for (auto it = mpp.begin(); it != mpp.end(); ++it) {
        ans += it->first;
    }
    return ans;
}

int main() {
    string str = "hello";
    string result = removeDuplicates(str);
    cout << "String after removing duplicates: " << result << endl;
    
    return 0;
}