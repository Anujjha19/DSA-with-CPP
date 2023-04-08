
/*  Time Complexity: O(1)
    Space Complexity: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<long long> s;
    long long mini;

public:
    MinStack()
    {
        while (s.empty() == false)
            s.top();
        mini = INT_MAX;
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            mini = val;
        }
        else
        {
            if (val > mini)
            {
                s.push(val);
            }
            else
            {
                long long ele = 2LL * val - mini; // Cast each term individually
                s.push(ele);
                mini = val;
            }
        }
    }

    void pop()
    {
        if (s.empty())
            return;

        if (s.top() < mini)
        {
            mini = 2 * mini - s.top();
        }

        s.pop();
    }

    void top()
    {
        if (s.empty())
            return;

        else if (s.top() < mini)
        {
            cout << mini;
        }
        else
        {
            cout << s.top();
        }
    }

    void getMin()
    {
        cout << mini;
    }
};

int main()
{
    MinStack s;

    // Take input from user
    s.push(-2);
    s.push(0);
    s.push(-3);

    // Function calls
    s.getMin();
    s.pop();
    s.top();
    s.getMin();

    return 0;
}

/* Solution 1: Using pairs to store the value and minimum element till now.
Time Complexity: O(1)
Space Complexity: O(2N)


#include <iostream>
#include <stack>
using namespace std;

struct MyStack{
    stack<pair<int, int>> st;
    int mini;

    void push(int x)
    {
        if (st.empty())
        {
            mini = x;
        }
        else
        {
            mini = min(x, st.top().second);
        }
        st.push({x, mini});
    }

    void pop()
    {
        int a = st.top().first;
        st.pop();
        cout << a << endl;
    }

    void getMin()
    {
        cout << st.top().second << endl;
    }

    void peek()
    {
        cout << st.top().first << endl;
    }
};

int main()
{
    MyStack s;

    // Take input from user
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    // Function calls
    s.getMin();
    s.pop();
    s.peek();
    s.getMin();

    return 0;
}

 */
