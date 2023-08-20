#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    int cnt = 0;
    int ans = INT_MAX;

    int i = 0, j = 0;
    int ns = n + m;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            cnt++;
            if (cnt == k)
            {
                ans = arr1[i];
                break;
            }
            i++;
        }
        else
        {
            cnt++;
            if (cnt == k)
            {
                ans = arr2[j];
                break;
            }
            j++;
        }
    }

    // If the k-th element is not found yet and one of the arrays is exhausted,
    // we need to continue searching in the remaining array.
    while (i < n && cnt < k)
    {
        cnt++;
        if (cnt == k)
        {
            ans = arr1[i];
            break;
        }
        i++;
    }

    while (j < m && cnt < k)
    {
        cnt++;
        if (cnt == k)
        {
            ans = arr2[j];
            break;
        }
        j++;
    }

    return ans;
}

//OS -> BS
int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}


int main()
{
    // Example usage
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    int n = arr1.size();
    int m = arr2.size();
    int k = 5;

    int kth = kthElement(arr1, arr2, n, m, k);
    cout << "The " << k << "-th element is: " << kth << endl;

    return 0;
}
