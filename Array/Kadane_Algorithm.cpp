
// Find Largest Sum contiguous Array

#include <bits/stdc++.h>
using namespace std;

/*  //Using 3 For Loop - TC [ O( N cube) ]
int maxSubArraySum(int a[], int size)
{
    int sum =0;
    for(int i=0; i<size ; i++){
        for(int j=i; j<size; j++){
            for( int k=i ; k<j ; k++){
                sum += a[k];
            }
        }
    }
    return sum;
} */

/* //Using 2 For Loop - TC [ O( N square ) ]
int maxSubArraySum(int a[], int size)
{
    int sum =0;
    for(int i=0; i<size ; i++){
        for(int j=i; j<size; j++){
                sum += a[j];
        }
    }
    return sum;
} */

// TC [ O( N ) ]
int maxSubArraySum(int a[], int size)
{
    int sum = 0;
    int maxi = a[0];
    for (int i = 0; i < size; i++)
    {
        sum = sum + a[i];
        maxi = max(maxi, sum);
        if (sum < 0){
            sum = 0;
        }
    }
    return maxi;
}
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


int main()
{
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(a) / sizeof(a[0]);

    /* //Printing All SubaArray
    for(int i=0; i<n ; i++){
        for(int j=i; j<n; j++){
            for( int k=i ; k<j ; k++){
                cout<< a[k] << " " ;
            }
        }
    } */

    // Function Call
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}