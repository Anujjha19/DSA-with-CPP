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

void reverseIterative(Node *&head)
{
    if (head == NULL)
        return;

    Node *prev = NULL;
    while (head != NULL)
    {
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
        /*  Node *curr = head->next;
         head->next = prev;
         prev = head;
         head = curr; */
    }
    head = prev;
}

Node *reverseRecursively(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *cHead = reverseRecursively(head->next);
    head->next->next = head;
    head->next = NULL;

    return cHead;
}
/*
Node* temp = NULL;
    Node* current = *head_ref;


    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head_ref = temp->prev;
 */
int main()
{

    Node *node1 = new Node(10);

    // Head
    Node *head = node1;
    insertAtHead(head, 20);
    insertAtHead(head, 50);
    insertAtHead(head, 70);
    print(head);

    cout << "Head " << head->data << endl;

    // reverseIterative(head);
    print(head);

    Node *ans = reverseRecursively(head);
    print(ans);
    return 0;
}