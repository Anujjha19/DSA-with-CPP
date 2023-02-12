#include <bits/stdc++.h>
using namespace std;

/* //Only Lower Case
int main()
{
    cout << "Enter Strings : ";
    string s;
    cin >> s;
    cout << endl;

    // Precompute
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }
    cout << " Enter TestCase : ";
    int t;
    cin >> t;
    while (t--)
    {
        cout << " Enter character to find ";
        char character;
        cin >> character;
        // fetch

        cout << hash[character - 'a'] << " " << endl;
    }

    return 0;
} */

//Storing all Characters  Upper case Lower case  , Other Characters

int main()
{
    cout << "Enter Strings : ";
    string s;
    cin >> s;
    cout << endl;

    // Precompute
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
    cout << " Enter TestCase : ";
    int t;
    cin >> t;
    while (t--)
    {
        cout << " Enter character to find ";
        char character;
        cin >> character;
        // fetch

        cout << hash[character] << " " ;
    }

    return 0;
}