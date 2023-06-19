#include <bits/stdc++.h>
using namespace std;

// Sorting
int print_all_unique(int arr[], int n)
{
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        while (i < n - 1 && arr[i] == arr[i + 1])
            i++;
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 4};
    cout << " Printing all Unique Element " << endl;
    print_all_unique(arr, 5);
    return 0;
}


// Hashing Un-ordered Map
void printDistinct(int arr[], int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        // if element is not present then s.count(element) return 0 else return 1
        // hashtable and print it
        if (!s.count(arr[i])) // <--- avg O(1) time
        {
            s.insert(arr[i]);
            cout << arr[i] << " ";
        }
    }
}

// Vector Sort
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{10, 5, 3, 4, 3, 5, 6};
    set<int> s(v.begin(), v.end());
    cout << "All the distinct element in given vector in sorted order are: ";
    for (auto it : s)
        cout << it << " ";
    cout << endl;
    return 0;
}
