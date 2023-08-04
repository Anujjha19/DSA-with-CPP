

#include <bits/stdc++.h>
using namespace std;


//2 Pointer
bool palindrome(string str)
{
    string y = str;
    int n = str.length();
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        swap(str[start++], str[end--]);
    }
    if (y == str)
        return true;
    else
        return false;
}

/* bool check_If_First_last_equal(string str)
{
    int n = str.length();
    int i = 0;
    while (i <= n / 2)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
} */

// Recursive Way
bool check_If_First_last_equal(int i, string &str)
{
    int n = str.length();
    if (i >= n / 2)
        return true;

    if (str[i] != str[n - i - 1])
        return false;

    return check_If_First_last_equal(i + 1, str);
}

int main()
{

    string s;
    cin >> s;

    if (palindrome(s) == 1)
        cout << "Yes  " << endl;
    else
        cout << "No  ";

    /* if (check_If_First_last_equal(s) == 1)
        cout << "Yes";
    else
        cout << "No"; */

    cout << check_If_First_last_equal(0, s);

    return 0;
}
// TC - O( N /2) = O( N );
// SC - O( N /2) = O( N );
