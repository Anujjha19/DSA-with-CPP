#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Stack
{
    queue<int> Q;

public:
    void push(int x)
    {
        int size = Q.size();
        Q.push(x);
        for (int i = 0; i < size; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
    }

    void pop()
    {
        if (Q.empty())
            return;
        cout << Q.front() << endl;
        Q.pop();
    }

    int top()
    {
        if (Q.empty())
            return -1;
        return Q.front();
    }

    int size()
    {
        return Q.size();
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size() << endl;
    cout << "top element: " << s.top() << endl;
    s.pop();
    cout << "top element: " << s.top() << endl;
    s.pop();
    cout << "top element: " << s.top() << endl;

    cout << "current size: " << s.size() << endl;
    return 0;
}
