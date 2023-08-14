#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeDuplicateLetters(string s) {
    string ans = "";
    vector<bool> map(52, false); // Update the size to accommodate both lowercase and uppercase letters
    for (int i = 0; i < s.length(); i++) {
        if (map[s[i] - 'A'] == false) { // Use 'A' instead of 'a' as the starting point for uppercase letters
            ans += s[i];
            map[s[i] - 'A'] = true;
        }
    }
    return ans;
}

int main() {
    string str = "cbacDcBc";
    cout << "Original String: " << str << endl;
    cout << "After removing duplicates: " << removeDuplicateLetters(str) << endl;
    return 0;
}