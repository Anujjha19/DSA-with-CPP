#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(nLogn)
void printBySorting(int arr[], int n)
{
    // sorting the array
    sort(arr, arr + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            cout << "Repeating No : " << arr[i] << endl;
            break;
        }
    }
    cout << "and the missing element is ";
    for (int i = 1; i < n; i++)
    {

        if (arr[i] - arr[i - 1] > 1)
        {
            cout << i;
        }
    }
}
int main()
{

    int arr[] = {1, 1, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printBySorting(arr, n);
    return 0;
}
/* int main()
{

    int arr[] = {1, 1, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int m = n;
    int hash[m] = {0};
    for (int i = 0; i < m; i++)
    {

        hash[arr[i]]++;
    }
    for (int i = 0; i < m; i++){
    
        // Check if element is repeating
        if (hash[arr[i]] == 2)
            cout << arr[i] << " is repeating\n";

        // Check if element is missing
        if (hash[arr[i]] == 0)
            cout << i << " is missing\n";
    }

    return 0;
}
 */