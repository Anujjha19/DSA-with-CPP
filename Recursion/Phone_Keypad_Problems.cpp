#include <bits/stdc++.h>
using namespace std;

void solve(string digits, string output, vector<string> &ans, int index, string mapping[])
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapping[number];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, ans, index + 1, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits)
{
    string output = "";
    vector<string> ans;

    if (digits.length() == 0)
        return ans;

    int index = 0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, ans, index, mapping);
    return ans;
}

int main()
{

    string digits = "23";
    vector<string> ans = letterCombination(digits);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}