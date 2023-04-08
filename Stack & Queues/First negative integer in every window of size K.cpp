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




void negativeIntegerInEveryWindoOfK()
{
    int k = 2; // assuming the value of k as 2

    if (front == -1 || rear == -1)
    { // Check if queue is empty
        cout << "Error: Queue is empty\n";
        return;
    }

    queue<int> q;
    int negativeCount = 0;
    vector<int> v;

    for (int i = front; i <= rear; i++)
    {
        q.push(arr[i]);

        if (q.size() == k)
        {
            negativeCount = 0;
            queue<int> tempQ = q;

            while (!tempQ.empty())
            {
                if (tempQ.front() < 0)
                {
                    negativeCount++;
                    v.push_back(tempQ.front());
                }
                tempQ.pop();
            }

            if (negativeCount == 0)
            { // If no negative numbers found in the window
                v.push_back(0);
            }

            q.pop();
        }
    }
    cout << "Negative Integers in current window: " << negativeCount << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    enqueue(-8);
    enqueue(2);
    enqueue(3);
    enqueue(-6);
    enqueue(10);
    display(); // Output should be: Elements of queue: -8 2 3 -6 10

    negativeIntegerInEveryWindoOfK();

    return 0;
}

/* #include <bits/stdc++.h>
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

vector<int> printFirstNegativeInteger(int A[], int N, int K)
{
    deque<int> dq;
    vector<int> ans;

    // process first window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // push ans for FIRST window
    if (!dq.empty())
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // now process for remaining windows
    for (int i = K; i < N; i++)
    {
        // first pop out of window element

        if (!dq.empty() && (i - dq.front()) >= K)
        {
            dq.pop_front();
        }

        // then push current element
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // put in ans
        if (!dq.empty())
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}

int main()
{
    enqueue(-8);
    enqueue(-100);
    enqueue(3);
    enqueue(-6);
    enqueue(10);
    display(); // Output should be: Elements of queue: -8 -100 3 -6 10

    vector<int> res = printFirstNegativeInteger(arr, 5, 2);

    // show output from function
    cout << "Output from printFirstNegativeInteger: ";
    for (auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
 */