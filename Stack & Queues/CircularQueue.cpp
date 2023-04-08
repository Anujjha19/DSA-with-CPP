#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front, rear;
    int n;
    int *arr;

public:
    Queue(int s)
    {
        front = -1;
        rear = -1;
        n = s;
        arr = new int[s];
    }

    void enQueue(int x)
    {
        // Full
        cout << "The Entered Data is : " << x << endl;
        if ((front == 0 && rear == n - 1) || (rear == (front - 1) % (n - 1)))
        {
            cout << "Queue Full";
            return;
        }
        // First Element
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            // arr[rear] = x;
        }
        // Circular Condition
        else if (rear == n - 1 && front != 0)
        {
            rear = 0;
            // arr[rear] = x;
        }
        // Normal Case
        else
        {
            rear++;
            // arr[rear] = x;
        }
        arr[rear] = x;
    }

    int deQueue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty " << endl;
        }
        int val = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == n - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        // cout << "The Removed Data is : " << val << endl;
        return val;
    }

    void displayQueue()
    {
        // Display all elements in the Queue
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        // If no Circular Array
        else if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            // front to the end of the array n-1
            for (int i = front; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            // from the beginning of the array to rear.
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Queue q(5);
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);
    q.displayQueue();
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
    cout <<endl;
    q.displayQueue();
    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);
    q.displayQueue();
    q.enQueue(20);
    return 0;
}
