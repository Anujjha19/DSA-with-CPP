#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = power(a, b / 2);
    if( b %2 == 0) {
        return ans * ans;
    }
    else{
        return (  a * ans * ans );
    }

    // return ans ;
}

int main()
{
    int base;
    int powerB;

    cout << "Enter the base number: ";
    cin >> base;

    cout << "Enter the powerB: ";
    cin >> powerB;

    int result = power(base, powerB);

    cout << base << " raised to the power of " << powerB << " is " << result << endl;

    return 0;
}
