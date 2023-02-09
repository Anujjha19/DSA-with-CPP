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

    //   No , Space , No
    void printMshpaeNo(int n)
    {
        int space = 2 * n - 1;
        for (int i = 1; i <= n; i++)
        {
            // NO
            for (int j = 1; j <= i; j++)
            {
                cout << j;
            }
            // Space
            for (int j = 1; j <= space; j++)
            {
                cout << " ";
            }
            // NO
            for (int j = i; j >= 1; j--)
            {
                cout << j;
            }
            cout << endl;
            space -= 2;
        }
    }

    void RHTcountIncrease(int n)
    {
        int count = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << count++ << " ";
            }
            cout << endl;
        }
    }

    void RHT_OnEachLine_PrintStarts_WIth_A(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (char ch = 'A'; ch <= 'A' + i; ch++)
            {
                cout << ch;
            }
            cout << endl;
        }
    }

    void InvertRHT_OnEachLine_PrintStarts_WIth_A(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
            {
                cout << ch;
            }
            cout << endl;
        }
    }

    void RHT_linePrint_A_ThenB_soOn(int n)
    {
        // char ch ='A';
        for (int i = 0; i < n; i++)
        {
            char ch = 'A' + i;
            for (int j = 0; j <= i; j++)
            {
                cout << ch << " ";
            }
            // ch=ch+1;
            cout << endl;
        }
    }

    // Til mid ch++ , then ch--

    void Triangle_A_ABA_ABCBA_Soon(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // Space
            for (int j = 0; j < (n - i - 1); j++)
            {
                cout << " ";
            }
            char ch = 'A';
            int breakPoint = (2 * i + 1) / 2;

            for (int j = 1; j <= (2 * i + 1); j++)
            {
                cout << ch;
                if (j <= breakPoint)
                    ch++;
                else
                    ch--;
            }
            // Space
            for (int j = 0; j < (n - i - 1); j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }

    void RHT_starts_NplaceLetter_in_EachLine_thenDecrement(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (char ch = 'E' - i; ch <= 'E'; ch++)
            {
                cout << ch << " ";
            }
            cout << endl;
        }
    }

    void Square_Midlle_Kite_Shape_Gap(int n)
    {
        //  stars . spaces . stars
        int spaces = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= n - i; j++)
            {
                cout << "*";
            }
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= n - i; j++)
            {
                cout << "*";
            }
            spaces += 2;
            cout << endl;
        }
        spaces = 2 * n - 2;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            spaces -= 2;
            cout << endl;
        }
    }

    void butterFly(int n)
    {
        int spaces = 2 * n - 2;
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            // Star Spaces Star
            int stars = i;
            if (i > n)
                stars = 2 * n - i;
            for (int j = 1; j <= stars; j++)
            {
                cout << "*";
            }

            for (int j = 1; j <= spaces; j++)
            {
                cout << " ";
            }

            for (int j = 1; j <= stars; j++)
            {
                cout << "*";
            }
            cout << endl;
            if (i < n)
                spaces -= 2;
            else
                spaces += 2;
        }
    }

    void printHollowSquare(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }

    void print_LIKE_a_Diagonal(int n)
    {
        for (int i = 0; i < 2 * n - 1; i++)
        {
            for (int j = 0; j < 2 * n - 1; j++)
            {
                int top = i;//row
                int left = j;//column
                int right = (2 * n - 1)-1 - j;
                int down = (2 * n - 1)-1 - i;
                cout << (n - ((min(top, down)), (min(left, right)) ) );
            }
            cout<<endl;
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

    // obj.print10alternateStairs(n);

    // obj.printMshpaeNo(n);

    // obj.RHTcountIncrease(n);
    // obj.RHT_OnEachLine_PrintStarts_WIth_A(n);
    // obj.InvertRHT_OnEachLine_PrintStarts_WIth_A(n);
    // obj.RHT_linePrint_A_ThenB_soOn( n);

    // obj.Triangle_A_ABA_ABCBA_Soon( n);
    // obj.RHT_starts_NplaceLetter_in_EachLine_thenDecrement(n);

    // obj.Square_Midlle_Kite_Shape_Gap(n);

    // obj.butterFly(n);

    // obj.printHollowSquare(n);

    obj.print_LIKE_a_Diagonal(n);

    return 0;
}