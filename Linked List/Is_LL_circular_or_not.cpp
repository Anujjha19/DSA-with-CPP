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
bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    // if (head->next == NULL){return false;}

    Node *temp = head->next;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
        return true;
    else
        return false;
}

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    
    unordered_set<Node*> visited;
    Node *temp = head;
    while (temp != NULL) {
        if (visited.find(temp) != visited.end()) {
            // If the node has already been visited, it is circular
            return true;
        }
        visited.insert(temp);
        temp = temp->next;
    }
    // If we reach the end of the list without finding a cycle, it is not circular
    return false;
}


int main()
{
    /*

    Node *tail = NULL;

    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 7, 9);
    insertNode(tail, 5, 6);
    insertNode(tail, 9, 10);
    insertNode(tail, 3, 4);
    print(tail);

    isCircular(tail) ? cout << "YES" : cout << "NO";
 */

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";

    // Making linked list circular
    head->next->next->next->next = head;

    isCircular(head) ? cout << "Yes\n" : cout << "No\n";
    return 0;
}