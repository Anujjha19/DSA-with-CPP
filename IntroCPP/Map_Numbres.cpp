#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mp;

    cout << "Enter n : ";
    int n;
    cin >> n;
    cout << endl
         << "Enter array element : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    /*
        // Precompute
        map<int , int > mp;
        for(int i=0; i< n ; i++){
            mp[arr[i]]++;
        } */

    // Itterator
    for (auto it : mp)
    {
        cout << it.first << " -> " << it.second << endl;
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

        cout << mp[number] << " " << endl;
    }

    return 0;
}