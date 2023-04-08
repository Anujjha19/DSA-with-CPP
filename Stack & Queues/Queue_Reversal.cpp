#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100 // Maximum size of the queue

int arr[MAX_SIZE];         // Declare queue
int front = -1, rear = -1; // Initial values of front and rear

// Function to insert an element into the queue
void enqueue(int x)
{
    if (rear == MAX_SIZE - 1)
    { // Check if queue is full
        cout << "Error: Queue is full\n";
        return;
    }
    if (front == -1 && rear == -1)
    { // If queue is empty
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = x; // Insert the element
}

// Function to remove an element from the queue
void dequeue()
{
    if (front == -1)
    { // Check if queue is empty
        cout << "Error: Queue is empty\n";
        return;
    }
    if (front == rear)
    { // If there is only one element in the queue
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// Function to print the elements of the queue
void display()
{
    if (front == -1)
    { // Check if queue is empty
        cout << "Error: Queue is empty\n";
        return;
    }
    cout << "Elements of queue: ";
    for (int i = front; i <= rear; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseQueueSTACK(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}
void reverseQueue(queue<int> &q)
{
    if( q.size() ==1 || q.empty()){
        return;
    }

    int FrontElement = q.front();
    q.pop();
    reverseQueue(q);
    q.push(FrontElement);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display(); // Output should be: Elements of queue: 10 20 30 40

    queue<int> q;
    for (int i = front; i <= rear; i++)
    {
        q.push(arr[i]);
    }

    reverseQueue(q);

    cout << "\nReversed Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}

/* #include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Original Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    q.push(10);
    q.push(20);
    q.push(30);
    reverseQueue(q);

    cout << "\nReversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
 */