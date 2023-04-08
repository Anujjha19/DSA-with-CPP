#include <bits/stdc++.h>
using namespace std;

void insertToBottom(stack<int> &S, int N)
{

    if (S.empty())
    {
        S.push(N);
        return;
    }

    int m = S.top();
    S.pop();
    insertToBottom(S, N);
    S.push(m);
}

int main()
{
    // Input
    stack<int> S;
    S.push(5);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);

    int N = 7;

    insertToBottom(S, N);
    // Print the elements of S
    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
}