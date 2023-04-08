#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Queue
{
    stack<int> S1, S2;

public:
    void push(int x)
    {
        while (!S1.empty())
        {
            S2.push(S1.top());
            S1.pop();
        }
        cout << "The element pushed is " << x << endl;

        S1.push(x);
        while (!S2.empty())
        {
            S1.push(S2.top());
            S2.pop();
        }
    }

    int pop()
    {
        if (S1.empty())
        {
            cout << "Empty ";
            exit(0);
        }

        int val = S1.top();
        S1.pop();
        return val;
    }

    int top()
    {
        if (S1.empty())
        {
            cout << "Empty ";
            exit(0);
        }

        return S1.top();
    }

    int size()
    {
        if (S1.empty())
        {
            cout << "Empty ";
            exit(0);
        }

        return S1.size();
    }
};

int main()
{
    Queue q;
    q.push(3);
    q.push(4);
    cout << "The element poped is " << q.pop() << endl;
    q.push(5);
    cout << "The top of the queue is " << q.top() << endl;
    cout << "The size of the queue is " << q.size() << endl;

    return 0;
}
