#include <bits/stdc++.h>
using namespace std;

void print(int n, int i)
{
    // Base Call
    if (i > n)
        return;

    cout << i << endl;
    print(n, i + 1);
}

void printReverseBacktracking(int n)
{
    // Base Call
    if (n == 0)
        return;

    cout << n << endl;
    printReverseBacktracking((n - 1));
        //cout << n << endl;

}

void printReverse(int n , int i)
{
    // Base Call
    if (i<1)
        return;

    cout << i << endl;
    printReverse(n , i- 1);
}

int main()
{
    int n;
    cin >> n;
    int i = 1;

    print(n, i);
    cout << endl;
    printReverse(n , n);

    cout << endl;
    printReverseBacktracking(n);
    return 0;
}
// T.C = o ( N )
// S.C = O ( N)