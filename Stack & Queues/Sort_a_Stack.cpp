#include <bits/stdc++.h>

using namespace std;

void insertinSortedOrder(stack<int> &S, int val)
{
    if (S.empty() || S.top() < val)
    {
        S.push(val);
        return;
    }
    int x = S.top();
    S.pop();
    insertinSortedOrder(S, val);
    S.push(x);
}

void SortAStack(stack<int> &S)
{
    if (S.empty())
    {
        return;
    }
    int x = S.top();
    S.pop();
    SortAStack(S);
    insertinSortedOrder(S, x);
}

int main()
{
    // Input
    stack<int> S;
    S.push(-1);
    S.push(7);
    S.push(3);
    S.push(10);
    S.push(1);

    cout << "Before Sorting : ";
    stack<int> S_copy = S;
    while (!S_copy.empty())
    {
        cout << S_copy.top() << " ";
        S_copy.pop();
    }
    
    SortAStack(S);

    cout << endl
         << "After Sorting : ";
    stack<int> sortedStack;

    while (!S.empty())
    {
        sortedStack.push(S.top());
        S.pop();
    }

    while (!sortedStack.empty())
    {
        cout << sortedStack.top() << " ";
        sortedStack.pop();
    }
    cout << endl;

    return 0;
}
