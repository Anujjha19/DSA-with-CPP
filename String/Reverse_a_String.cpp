#include <bits/stdc++.h>
using namespace std;

// Function to reverse a string
void reverseStr(string &str)
{
    int len = str.length();
    int end = len - 1;
    int start = 0;
    while (start <= end)
    {
        // Using the swap method to switch values at each index
        swap(str[start], str[end]);
        end = end - 1;
        start = start + 1;
    }
}
// Recursive
/* void reverseStr(string& str, int n, int i)
{
    if(n<=i){return;}
    swap(str[i],str[n]);
    reverseStr(str,n-1,i+1);

} */
int main()
{
    string str = "geeksforgeeks";
    reverseStr(str);
    cout << str;
    return 0;
}
// TC & SC  - O(N)