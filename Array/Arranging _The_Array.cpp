//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void Rearrange(int arr[], int n)
{
    int j = 0;
    vector<int> negative;
    vector<int> positive;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            negative.push_back(arr[i]);
        }
        else
        {
            positive.push_back(arr[i]);
        }
    }

    for (int i = 0; i < positive.size(); i++)
    {
        negative.push_back(positive[i]);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = negative[i];
    }
}
int main()
{

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];


        Rearrange(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    
    return 0;
}
