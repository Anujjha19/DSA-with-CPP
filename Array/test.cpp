#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {1, 1, 2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // MISSing No
    int xor1 = arr[0];

    for (int i = 1; i < n; i++)
    {
        xor1 = xor1 ^ arr[i];
    }

    /*  int ans = 0 ; 
    
    for(int i=0 ; i<N-1 ; i++){
        ans = ans^A[i];
    }
    for(int i=1 ; i<=N ; i++){
        ans = ans^i;
    }
    
    return ans ; */

    cout << "Missing No : " << xor1 << endl;


    return 0;
}

/* 
int sum=0;

    for(int i=0;i<N-1;i++)

    {

        sum+=A[i];

    }

    return (N*(N+1)/2)-sum; */