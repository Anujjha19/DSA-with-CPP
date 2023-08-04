#include <bits/stdc++.h>
using namespace std;

// Pick Not Pick
void subSequence(int index, int arr[], int n, vector<int> &ans)
{
    if (index == n)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        if (ans.size() == 0)
        {
            cout << "{}";
        }
        cout << endl;
        return;
    }

    // Pick
    ans.push_back(arr[index]);
    subSequence(index + 1, arr, n, ans);
    ans.pop_back();
    // Not Pick
    subSequence(index + 1, arr, n, ans);
}

// Bit Manipulation
vector<string> AllPossibleStrings(string s)
{
    int n = s.length();
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            // check if the ith bit is set or not
            if (num & (1 << i))
            {
                sub += s[i];
            }
        }
        if (sub.length() > 0)
        {
            ans.push_back(sub);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// Pick-Not Pick
void solve(int i, string s, string &f)
{
    if (i == s.length())
    {
        cout << f << " ";
        return;
    }
    // picking
    f = f + s[i];
    solve(i + 1, s, f);
    // poping out while backtracking
    f.pop_back();
    solve(i + 1, s, f);
}

int main()
{

    // 1 st
    int arr[3] = {3, 1, 2};
    vector<int> ans;

    // printint all the subsequence.
    cout << " Subsequences :  " << endl;
    subSequence(0, arr, 3, ans);

    // 2 nd
    string s = "abc";
    vector<string> all_SubSeq = AllPossibleStrings(s);
    // printint all the subsequence.
    cout << "All possible subsequences are " << endl;
    for (auto it : all_SubSeq)
    {
        cout << it << " ";
    }

    // 3 rd
    string s = "abc";
    string f = "";
    cout << "All possible subsequences are: " << endl;
    solve(0, s, f);
}
