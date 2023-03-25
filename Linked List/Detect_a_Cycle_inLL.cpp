#include <bits/stdc++.h>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constrcutor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};
// Insertion

void insertNode(Node *&tail, int element, int d)
{

    // empty list
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        // non-empty list
        // assuming that the element is present in the list

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found -> curr is representing element wala node
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// Traversal
void print(Node *tail)
{

    Node *temp = tail;
    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

// Deletion

void DeletionCLL(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == prev)
        {
            tail = NULL;
        }
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

/* bool detectLoop(Node *head)
{
    if (head == NULL)
        return false;
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {// cycle is present 
            if(visited [temp] == true) {
            return true;
    }
    visited[temp] = true;
    temp = temp->next;
}
return false;
} */

bool isCycle_Hashing(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    unordered_set<Node *> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited.find(temp) != visited.end())
        {
            // If the node has already been visited, it is circular
            return true;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    // If we reach the end of the list without finding a cycle, it is not circular
    return false;
}

bool hasCycle_Floyds_algo(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    if (head == NULL || head->next == NULL)
        return false;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return true;
    }
    return false;
}

int main()
{
    Node *head = new Node(20);

    // Inserting Node in Linked List
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(10);

    // Just to make a cycle
    head->next->next->next->next = head;

    isCycle_Hashing(head) ? cout << "Loop Detected \n" : cout << " No Loop Detected \n";

    hasCycle_Floyds_algo(head) ? cout << "Loop Detected \n" : cout << " No Loop Detected \n";

    return 0;
}