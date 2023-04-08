#include <bits/stdc++.h>
using namespace std;

void reverseK(queue<int> &q, int k)
{
    if (q.empty() == true || k > q.size())
    {
        cout << "Invalid value of k or queue is empty" << endl;
        return;
    }
    stack<int> s;
    for( int i =0 ; i<k ; i++){
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for( int i =0; i< q.size() -k ; i++){
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    int n, x, k;
    cout << "Enter no of elements in queue:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ":";
        cin >> x;
        q.push(x);
    }
    cout << "Enter the value of K: ";
    cin >> k;
    reverseK(q, k);
    cout << "Queue after reversing first " << k << " elements: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
