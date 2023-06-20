#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int N)
{
    for (int i = 1; i <= N; i++)
    {
        // flag variable to check if an element exists
        int flag = 0;
        // Search the element using linear search:
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] == i)
            {
                // i is present in the array:
                flag = 1;
                break;
            }
        }
        // check if the element is missing i.e flag == 0:

        if (flag == 0)
            return i;
    }

    return -1;
}

int missingNumber(int A[], int N)
{
    int sum = (N * (N + 1)) / 2;

    // Summation of all array elements:
    int s2 = 0;
    for (int i = 0; i < N - 1; i++)
    {
        s2 += A[i];
    }

    int missingNum = sum - s2;
    return missingNum;
}

int missingNumber(vector<int> &a, int N)
{

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++)
    {
        xor2 = xor2 ^ a[i];    // XOR of array elements
        xor1 = xor1 ^ (i + 1); // XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; // XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main()
{
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
