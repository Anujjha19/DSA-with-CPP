/* #include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front, rear, n, Csize;
    int *arr;

public:
    Queue(int s)
    {
        this->n = s;
        this->Csize = 0;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return 1;
        else
            return 0;
    }
    bool isFull()
    {
        return (rear == n - 1);
    }

void push(int x)
{
    if (Csize == n)
    {
        cout << "Overflow: Queue Full\n";
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        arr[rear  % n] = x;
        rear++;
        Csize++;
    }
}

    int pop()
    {
        if (Csize == 0)
        {
            cout << " Empty UnderFlow ";
            return 1;
        }
        else
        {
            int a = arr[front % n];
            arr[front % n] = -1;
            front++;
            Csize--;

            return a;
        }
    }

   c

    int size()
    {
        return Csize;
    }
    int topPeek()
    {
        if (Csize == 0)
        {
            return 0;
        }
        else
        {
            return arr[front % n];
        }
    }
};

int main()
{
    Queue q(4);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);

    q.print();
    cout << q.size() << endl;
    cout << q.topPeek() << endl;

    q.pop();
    q.print();
    cout << q.topPeek() << endl;

    q.push(100);
    q.print();
    // cout << q.topPeek() << endl;

    return 0;
} */
#include <iostream>
using namespace std;

const int MAX_SIZE = 4; // maximum size of the queue

class Queue
{
private:
    int front;         // index of the front element
    int rear;          // index of the rear element
    int arr[MAX_SIZE]; // array to store queue elements
    int Csize;

public:
    Queue()
    { // constructor
        front = -1;
        rear = -1;
        Csize = 0;
    }

    bool is_empty()
    { // check if the queue is empty
        return (front == -1 && rear == -1);
    }

    bool is_full()
    { // check if the queue is full
        return ((rear + 1) % MAX_SIZE == front);
    }

    void enqueue(int x)
    { // add an element to the rear of the queue
        if (is_full())
        {
            cout << "Error: Queue is full\n";
            return;
        }
        else if (is_empty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            Csize++;
        }
        arr[rear] = x;
    }
    /*  if ( cSize == n) return -1
    else
    arr[rear%n] =x  ;
    rear++;
    */

    void dequeue()
    { // remove an element from the front of the queue
        if (is_empty())
        {
            cout << "Error: Queue is empty\n";
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
            Csize--;
        }
    }
     /*  if ( cSize == 0) return -1
    else
    arr[front % n]  = -1  ;
    front ++;
    */

    int peek()
    { // get the value of the front element without removing it
        if (is_empty())
        {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int size()
    {
        return Csize + 1;
    }

    void print()
    { // print the elements of the queue
        if (is_empty())
        {
            cout << "Queue is empty\n";
        }
        else
        {
            cout << "Queue: ";
            int i = front;
            while (i != rear)
            {
                cout << arr[i] << " ";
                i = (i + 1) % MAX_SIZE;
            }
            cout << arr[rear] << endl;
        }
    }
};

int main()
{

    Queue q;
    q.enqueue(4);
    q.enqueue(14);
    q.enqueue(24);
    q.enqueue(34);

    q.print();
    cout << q.size() << endl;
    cout << q.peek() << endl;

    q.dequeue();
    q.print();
    cout << q.peek() << endl;

    q.enqueue(100);
    q.print();
    cout << q.peek() << endl;

    return 0;
}


/* #include <bits/stdc++.h> 

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;
    
public:
    Queue() {

        size=100001;
        arr= new int[size];
        qfront=0;
        rear=0;
        
    }


    bool isEmpty() {

        if(qfront==rear){
            return true;
            
        }else{
            return false;
        }
    }

    void enqueue(int data) {

        if(rear ==size){
            cout<<"Queue is Full"<<endl;
        }else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {

        if(qfront==rear){
            return -1;
        }else{
                    int ans = arr[qfront];
            arr[qfront]=-1;
            qfront++;
            
            if(qfront==rear){
            qfront=0;
            rear=0;}
                    return ans;
        }
    }

    int front() {
        
        if(qfront==rear){
            return -1;
        }else{
            return arr[qfront];
        }
        
        
    }
}; */