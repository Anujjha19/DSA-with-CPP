#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &S, int val)
{
    if (S.empty())
    {
        S.push(val);
        return;
    }

    int x = S.top();
    S.pop();
    insertAtBottom(S, val);
    S.push(x);
}

void Reverse_a_Stack(stack<int> &S)
{
    if (S.empty())
    {
        return;
    }

    int x = S.top();
    S.pop();
    Reverse_a_Stack(S);

    insertAtBottom(S, x);
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

    // Print the stack before reversal
    cout << "Stack before reversal: ";
    stack<int> S_copy = S; // create a copy of S
    while (!S_copy.empty())
    {
        cout << S_copy.top() << " ";
        S_copy.pop();
    }
    cout << endl;

    Reverse_a_Stack(S);

    // Print the stack after reversal
    cout << "Stack after reversal: ";
    while (!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;

    return 0;
}
