#include <bits/stdc++.h>
using namespace std;

void print(string s, int n, int i)
{
    // Base Call
    if (i > n)
        return;

    cout << s << endl;
    print(s, n, i + 1);
}
int main()
{
    cout << "Name : ";
    string s;
    cin >> s;
    cout << "No of Times to Print : ";
    int n;
    cin >> n;

    int i = 1;

    print(s, n, i);
    return 0;
}
// T.C = o ( N )
// S.C = O ( N)