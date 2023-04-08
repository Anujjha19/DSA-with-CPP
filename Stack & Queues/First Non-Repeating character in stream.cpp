#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

string firstNonRepeatingChar(string s)
{
    unordered_map<char, int> freq;
    queue<char> q;
    string result = "";
    for (char c : s)
    {
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1)
        {
            q.pop();
        }

        if (q.empty())
        {
            result += "#";
        }

        else
        {
            result += q.front();
        }
    }
    return result;
}

int main()
{
    string s = "aabc";
    cout << firstNonRepeatingChar(s) << endl; // Output: a#bb
    return 0;
}
