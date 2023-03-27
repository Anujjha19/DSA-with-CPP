// C++ program for the above approach
#include <bits/stdc++.h>

using namespace std;

bool chkPair(int A[], int size, int x)
{
    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = (i + 1); j < size; j++)
        {
            if (A[i] + A[j] == x)
            {
                return 1;
            }
        }
    }

    return 0;
}
int main()
{
    int A[] = {0, -1, 2, -3, 1};
    int x = -2;
    int size = sizeof(A) / sizeof(A[0]);

    if (chkPair(A, size, x))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << x << endl;
    }

    return 0;
}

/* APPROACH 1 : using nested loops (Gives TLE)

COMPLEXITIES :

TC = O(N^2)
SC = O(1)

bool hasArrayTwoCandidates(int arr[], int n, int x)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (arr[i] + arr[j] == x)
                return true;
        }
    }
    return false;
} */

/* APPROACH 2 : using hashing(Accepted😺)

COMPLEXITIES :

    TC = O(N)
        SC = O(N)
            CODE :

bool hasArrayTwoCandidates(int arr[], int n, int x) {
        unordered_set<int> s;
        for( int i=0 ; i< n; i++){
            int temp = x - arr[i];
            if( s.find(temp) != s.end())
                return true ;

            s.insert(arr[i]);
        }
        return false;
    }
 */

/* APPROACH 3 : using two pointer approach(Accepted😺)

COMPLEXITIES :
TC = O(N)
SC = O(1)

bool hasArrayTwoCandidates(int arr[], int n, int x)
{

    sort(arr, arr + n);

    int i = 0, j = n - 1;

    while (i < j)
    {
        int sum = arr[i] + arr[j];

        if (sum == x)
            return true;
        else if (sum < x)
            i++;
        else
            j--;
    }
    return false;
}
 */