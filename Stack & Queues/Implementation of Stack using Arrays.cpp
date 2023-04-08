#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int top, size;
    int *arr;

public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        int a = arr[top];
        top--;
        return a;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return (top + 1);
    }
    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
};

int main()
{

    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}
// Time Complexity: O(N)
// Space Complexity: O(N)

/* Conditions Each
#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int top, size;
    int *arr;

public:
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }
    void push(int x)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = x;
        }
        else
        {
            cout << " Overflow Stack ";
        }
    }

    int pop()
    {
        if (top >= 0)
        {
            int a = arr[top];
            top--;
            return a;
        }
        else
        {
            cout << " Underflow Stack ";
        }
    }

    int Top()
    {
        if( top >=0 && top < size){
        return arr[top];
        }
        else{
            cout << "Stack EMPTY";
            return -1;
        }
    }
    int Size()
    {
        return (top + 1);
    }
    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
};

int main()
{

    Stack s(5);
    s.push(6);
    s.push(10);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}

 */