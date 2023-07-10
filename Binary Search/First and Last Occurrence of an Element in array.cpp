#include <iostream>
#include <vector>

using namespace std;

pair<int, int> solve(int n, int k, const vector<int> &arr)
{
    int n = arr.size();
    int first = -1;
    int last = -1;

    // Find the first occurrence position
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            first = i;
            break;
        }
    }

    // Find the last occurrence position
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == k)
        {
            last = i;
            break;
        }
    }

    return make_pair(first, last);
}

// BINARY SEARCH
int findFirstOccurrence(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
        {
            result = mid;
            high = mid - 1; // continue searching towards the left
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(vector<int> &arr, int k)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            result = mid;
            low = mid + 1; // continue searching towards the right
        }
        else if (arr[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int k)
{
    int first = findFirstOccurrence(arr, k);
    int last = findLastOccurrence(arr, k);
    return make_pair(first, last);
}

int main()
{
    int n = 7;
    int key = 13;
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};

    pair<int, int> ans = firstAndLastPosition(v, key);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
