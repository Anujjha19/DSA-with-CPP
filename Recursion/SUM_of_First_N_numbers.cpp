

#include <iostream>
using namespace std;

void sumofFirstNno_ParametrisedWay(int n, int sum)
{
    if (n < 1)
    {
        cout << " Sum Is : " << sum << endl;
        return;
    }
    else
    {
        sumofFirstNno_ParametrisedWay(n - 1, sum + n);
    }
}

int sumofFirstNno_Recursion_Functional(int n)
{
    if (n == 0)
        return 0;
    else
    {
        return n + sumofFirstNno_Recursion_Functional(n - 1);
    }
}
int Factorial(int n)
{
    if (n == 0)
        return 1;
    else
    {
        return n * Factorial(n - 1);
    }
}

int main()
{

    int n;
    cin >> n;

    sumofFirstNno_ParametrisedWay(n, 0);
    cout << endl;

    cout << " Sum Is : " << sumofFirstNno_Recursion_Functional(n);

    cout << endl
         << " Factorial Is : " << Factorial(n);
}

// TC - O( N) & SC - O( N)