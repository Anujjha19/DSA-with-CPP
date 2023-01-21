#include <bits/stdc++.h>
using namespace std;

void getUnion(int a[], int n, int b[], int m)
{
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp.insert({a[i], i});

    for (int i = 0; i < m; i++)
        mp.insert({b[i], i});

    cout << "The union set of both arrays is :" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
        cout << itr->first
             << " ";
}

void getUnion(int a[], int n, int b[], int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);
    for (int i = 0; i < m; i++)
        s.insert(b[i]);
    cout << "Number of elements after union operation: "
         << s.size() << endl;
    cout << "The union set of both arrays is :" << endl;
    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " "; // s will contain only distinct
                             // elements from array a and b
}

int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    // Your code goes here
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        int key = b[i];
        if (s.find(key) != s.end())
            count++;
        s.erase(b[i]); // remove the already counted element , otherwise
                       // it would be counted multiple times.
    }
    return count;
}

int getIntersecton(int c[], int n, int d[], int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (c[i] == d[j])
            {
                cout << c[i] << " " << endl;
            }
        }
    }
}
