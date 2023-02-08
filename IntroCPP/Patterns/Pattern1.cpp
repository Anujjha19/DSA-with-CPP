#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void printSquare(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << " * ";
            }
            cout << endl;
        }
    }

    void printStairs(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << " * ";
            }
            cout << endl;
        }
    }

    void printNoStairs1(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j;
            }
            cout << endl;
        }
    }

    void printNoStairs2(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    void revStairs(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (n - i + 1); j++)
            {
                cout << " * ";
            }
            cout << endl;
        }
    }

    void revNo(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= (n - i + 1); j++)
            {
                cout << " j ";
            }
            cout << endl;
        }
    }

    // Space = ( n - i - 1)
    // Stars  =2 ( i + 1)
    void triangle(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // space
            for (int j = 0; j < (n - i - 1); j++)
            {
                cout << " ";
            }
            // stars
            for (int j = 0; j < 2 * i + 1; j++)
            {
                cout << "*";
            }
            // space
            for (int j = 0; j < (n - i - 1); j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }

    // Space = ( i )
    // Stars  =2n - ( 2i + 1)
    void Revtriangle(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // space
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            // stars
            for (int j = 0; j < 2 * n - (2 * i + 1); j++)
            {
                cout << "*";
            }
            // space
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }

    void kite(int n)
    {

        triangle(n);
        Revtriangle(n);
    }

    void Oneto5and4to1(int n)
    {
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            int stars = i;
            if (i > n)
                stars = 2 * n - i;
            for (int j = 1; j <= stars; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }

    void print10alternateStairs(int n)
    {
        int start = 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                start = 1;
            else
                start = 0;

            for (int j = 0; j <= i; j++)
            {
                cout << start;
                start = 1 - start;
            }
            cout << endl;
        }
    }
    
};

int main()
{
    cout << "Enter Input  " << endl;
    int n;
    cin >> n;

    Solution obj;
    // obj.printSquare(n);

    // obj.printStairs(n);
    // obj.printNoStairs1(n);
    // obj.printNoStairs2(n);

    // obj.revStairs(n);
    // obj.revNo(n);

    // obj.triangle(n);
    // obj.Revtriangle(n);

    // obj.kite(n);

    // obj.Oneto5and4to1( n);

    obj.print10alternateStairs(n);

    return 0;
}