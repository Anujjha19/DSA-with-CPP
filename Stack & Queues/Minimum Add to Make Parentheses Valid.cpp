/* No of Bracket Need to Make Valid 

 */





#include <bits/stdc++.h>
using namespace std;


    int minAddToMakeValid(string s) {
        int open = 0; // number of excess opening parentheses
        int close = 0; // number of excess closing parentheses
        for (char c : s) {
            if (c == '(') {
                open++;
            } else if (c == ')' && open > 0) {
                open--;
            } else { // c == ')'
                close++;
            }
        }
        return open + close;
    }


int main()
{

    string p = "{}}";

    cout << minAddToMakeValid(p);
    return 0;
}

