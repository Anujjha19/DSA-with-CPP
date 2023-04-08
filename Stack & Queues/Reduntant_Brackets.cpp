
#include <bits/stdc++.h>
using namespace std;

bool findRedundant(string &str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isReduntant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isReduntant = false;
                    }
                    st.pop();
                }
            if( isReduntant == true) return true;
            st.pop();
            }
        }
    }
    return false;
}
int main()
{
    string str = "((a+b))";
    if(findRedundant(str) == true ) cout << " True YES ";
    else cout << " False NO " ;
    return 0;
}
