#include <bits/stdc++.h>
using namespace std;

// No Of Digit after Extracting 7789 mai 9 , 8 , 7 , 7
int count(int n)
{

    // TC - O( log 10(N)) -- If its divided by 2 then log base 2 , if 5 then log base5
    int cnt = 0;
    while (n > 0)
    {
        // int LD = n %10;
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;

    int cntLog = (int)(log10(n) + 1);
    return cntLog;
}

// Reverse A No - 1234 = 4321 , 14400 = 441
int reverse(int n)
{

    int revNo = 0;
    while (n > 0)
    {
        int LD = n % 10;
        revNo = revNo * 10 + LD;
        n = n / 10;
    }
    return revNo;
}

// Check Palindrome
bool palindrome(int n)
{
    int dup = n;
    if (dup == reverse(n))
        return true;
    else
        return false;
}

// Amstrong No  - Taking Cube of Each Digt == Sum then it is a AN
bool amstrong(int n)
{
    int dummy = n;
    int cntDigits = (int)(log10(n) + 1);

    int sum = 0;
    while (n > 0)
    {
        int LD = n % 10;
        sum += pow(LD, cntDigits);
        n = n / 10;
    }

    if (dummy == sum)
        return true;
    else
        return false;
}

void printALLDivisors(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << ' ';
}

// Till Square Root N
void printALLDivisorsOptimize(int n)
{
    vector<int> v;

    // for (int i = 1; i <= sqrt(n); i++)
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if ((n / i) != i)
            {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto it : v)
    {
        cout << it << " ";
    }

    // TC - O( sqrt n) + O (  log n ) + O( n )
}

// Check For Prime
bool primeNo(int n)
{
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }
    if (count == 2)
        return true;
    else
        return false;
}

// Optimized Prime No
bool primeNoOptimize(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
            {
                count++;
            }
        }
    }
    if (count == 2)
        return true;
    else
        return false;
}

// GCD or HCF
int GCD(int n1, int n2)
{
    /* int gcd=1;
    for( int i=1 ; i< min( n1, n2) ; i++){
        if( n1 % i == 0 && n2 % i ==0){
            gcd =i;
        }
    }
    return gcd; */

    int gcd = min(n1, n2);
    while (gcd > 0)
    {
        if (n1 % gcd == 0 && n2 % gcd == 0)
        {
            break;
        }
        gcd--;
    }
    return gcd;
    // TC - Min( n1 , n2 )
}

int Euclidean_Algorithm_GCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }

    if (a == 0)
        return b;
    else
        return a;

    // TC - O ( log phy ( min [ a , b ] ))
}

int main()
{

    cout << " Enter Number : ";
    int n;
    cin >> n;

    // cout<< " No Of Digit : " << count(n) << endl;
    // cout<< " Reverse of a No is : " << reverse(n) << endl;

    // cout << " Are the No is a Palindrome : " << palindrome(n) << endl;
    // cout << " Are the No is a Amstrong Number : " << amstrong(n) << endl;

    // cout << " All The Divisors of No are  : " << endl;
    // printALLDivisors(n);
    // cout << " All The Divisors of No are  : " << endl;
    // printALLDivisorsOptimize(n);

    // cout << " Are The No Is Prime : " << primeNo(n) << endl;
    // cout << " Are The No Is Prime : " << primeNoOptimize(n) << endl;

    cout << " N1 : ";
    int n1;
    cin >> n1;
    cout << endl
         << " N2 : ";
    int n2;
    cin >> n2;

    cout << " GCD of two No is : " << GCD(n1, n2) << endl;
    cout << " GCD of two No is : " << Euclidean_Algorithm_GCD(n1, n2) << endl;

    return 0;
}