#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    // int mid = (s + e) / 2;
    int mid = s + ((e - s) / 2);

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return true;
        }
        else if (key > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        // mid = (e + s) / 2;
        mid = s + ((e - s) / 2);
    }
    return false;
}

// Recursive
int binarySearch(vector<int> &nums, int low, int high, int target)
{

    if (low > high)
        return -1; // Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target)
        return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}
int search(vector<int> &nums, int target)
{
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    int odd[5] = {1, 6, 10, 25, 50};
    int even[6] = {1, 6, 10, 25, 50, 70};
    int key = 2;

    bool ansEven = binarySearch(odd, 5, key);
    bool ansOdd = binarySearch(even, 6, key);

    cout << " EVEN Ans : " << ansEven << endl;
    cout << "  ODD Ans : " << ansOdd << endl;

/*     // STL
    if (binary_search(odd.begin(), odd.end(), key))
        cout << "True"; */
}