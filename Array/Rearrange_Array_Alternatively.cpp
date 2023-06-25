// Taking Auxillary Space

#include <bits/stdc++.h>
using namespace std;

void rearrange7(long long *arr, int n)
{
    /*      int output[n];
            int i = 0, j = n - 1, k = 0;
            while (i <= j)
            {
                output[k++] = arr[j--];
                output[k++] = arr[i++];
            }
            for (int i = 0; i < n; i++){
            cout << output[i] << " ";
            cout << endl;
        } */
}
    void rearrange(long long *arr, int n)
    {
        // Your code here
        int max = arr[n - 1] + 1;
        int mini = 0;
        int maxi = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                arr[i] = (arr[i] + ((arr[maxi] % max) * max));
                maxi--;
            }
            else
            {
                arr[i] = (arr[i] + ((arr[mini] % max) * max));
                mini++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i] / max;
        }
    
}
int main()
{
    int n = 6;
    long long arr[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";

    // calling rearrange() function
    rearrange(arr, n);
    return 0;
}
