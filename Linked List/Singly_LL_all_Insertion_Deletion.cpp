#include <bits/stdc++.h>
using namespace std;
// Node Class
class Node
{
public:
    int data;
    Node *next;

    // Constructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        int vlaue = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};

// Inserting at Head
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Inserting at Tail
void insertAtTail(Node *&tail, int data)
{

    Node *temp = new Node(data);
    tail->next = temp;
    // tail = tail->next;
    tail = temp;
}

// Inserting at Tail -- IGNORE
void insertAtTail2(Node *&tail2, int data)
{

    Node *temp = new Node(data);
    tail2->next = temp;
    // tail2 = tail->next;
    tail2 = temp;
}

// Inserting at Middle
void insertAtPosition(Node *&head2, Node *&tail2, int position, int data)
{
    // solving First Node Case
    if (position == 1)
    {
        insertAtHead(head2, data);
        return;
    }
    Node *temp = head2;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }


    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    if( temp -> next == NULL){
        insertAtTail2( tail2 , 2);
        return;
    }
    
}

// Traversing a LL
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Deleting a Node by Position

void nodeDeletion(Node *&head2, Node *&tail2, int position)
{

    if (position == 1)
    {
        Node *temp1 = head2;
        head2 = head2->next;
        temp1->next = NULL;
        delete temp1;
    }
    else // Middle and Last Node Delete
    {
        /* Node *temp = head2;
        int count = 1;
        while (count < position - 1)
        {
            temp = temp->next;
            count++;
        }

        Node *curr = temp->next;
        temp->next = curr->next;
        curr->next = NULL;
        // {delete curr; }
        */

        Node *curr = head2;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        // Placing Tail at it's right postion
        if (prev->next == NULL)
        {
            tail2 = prev;
        }
    }
}

int main()
{

    Node *node1 = new Node(10);
    /* cout << node1->data << endl;
    cout << node1->next << endl; */

    // Head
    Node *head = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 50);
    insertAtHead(head, 70);
    print(head);
    // 70 50 20 10

    // Tail
    Node *tail = node1;
    print(head);
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    print(head);

    // Middle

    Node *node2 = new Node(100);
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAtHead(head2, 20);
    insertAtHead(head2, 50);

    insertAtPosition(head2, tail2, 2, 200);
    print(head2);

    insertAtPosition(head2, tail2, 1, 900);
    print(head2);

    // cout << head2->data <<" " ;
    // cout << tail2 ->data;

    // Deletion at First
    nodeDeletion(head2, tail2, 1);
    print(head2);

    // Deletion At middle or Last
    nodeDeletion(head2, tail2, 2);
    print(head2);

    nodeDeletion(head2, tail2, 3);
    print(head2);

    return 0;
}