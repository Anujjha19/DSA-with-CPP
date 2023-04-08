#include <iostream>

using namespace std;

class Deque
{

    int front;
    int rear;
    int n;
    int *arr;

public:
    Deque(int s)
    {
        // Constructor
        front = -1;
        rear = -1;
        n = s;
        arr = new int[n];
    }

    bool isEmpty()
    { 
        // Check if deque is empty
        if (front == -1)
        {
            cout << "Empty Queue " << endl;
        }
    }

    void insertFront(int val)
    {
        // Insert at the front
        cout << "The Entered Data is -> from Front: " << val << endl;
        if ((front == 0 && rear == 0) || (rear == (front - 1) % (n - 1)))
        {
            cout << " Queue is Full " << endl;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0 && rear != n-1 )
        {
            front = n - 1;
        }
        else
        {
            front--;
        }

        arr[front] = val;
    }

    void insertRear(int val)
    { // Insert at the rear
        cout << "The Entered Data is  -> from Rear: " << val << endl;
        if ((front == 0 && rear == 0) || (rear == (front - 1) % (n - 1)))
        {
            cout << " Queue is Full " << endl;
        }

        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == n - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = val;
    }

    void deleteFront()
    { // Remove from front
        if (front == -1)
        {
            cout << "Empty Queue " << endl;
        }
        cout << "The Removed Data is -> from Front : " << arr[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == n - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void deleteRear()
    { // Remove from rear
        if (front == -1)
        {
            cout << "Empty Queue " << endl;
        }
        cout << "The Removed Data is -> from Rear : " << arr[rear] << endl;
        
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = n - 1;
        }
        else
        {
            rear--;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Empty Deque" << endl;
            return;
        }
    
        cout << "Deque Elements: ";
        int i = front;
        if (front <= rear)
        {
            while (i <= rear)
            {
                cout << arr[i] << " ";
                i++;
            }
        }
        else
        {
            while (i < n)
            {
                cout << arr[i] << " ";
                i++;
            }
            i = 0;
            while (i <= rear)
            {
                cout << arr[i] << " ";
                i++;
            }
        }
        cout << endl;
    }
    
};

int main()
{
    Deque dq(5);

    dq.insertFront(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertRear(40);

    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    dq.display();

    return 0;
}
