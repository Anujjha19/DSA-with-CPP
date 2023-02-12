#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter n : ";
    int n;
    cin >> n;
    cout << endl
         << "Enter array element : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Precompute
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }
    cout << " Enter TestCase : ";
    int t;
    cin >> t;
    while (t--)
    {
        cout << endl
             << " Enter number to find ";
        int number;
        cin >> number;
        // fetch

        cout << hash[number] << " " << endl;
    }

    return 0;
}

/* 5
1 3 2 1 3
5
1
4
2
3
12 */