#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string longestCommonPrefix(string arr[], int N)
{
    sort(arr, arr + N);
    string f = arr[0];
    string l = arr[N - 1];

    string ans = "";

    for (int i = 0; i < arr[0].length(); i++)
    {
        if (f[i] == l[i])
        {
            ans += f[i];
        }
        else
            break;
    }

    if (ans == "")
        return "-1";

    return ans;
}

int main()
{
    string arr[] = { "anuj" , "anujjha" , "anu"};
    int size = sizeof(arr) / sizeof(arr[0]);
    string result = longestCommonPrefix(arr, size);
    cout << "Longest common prefix: " << result << endl;
    
    return 0;
}
