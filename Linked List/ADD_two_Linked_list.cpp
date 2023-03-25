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

Node *add2LL(Node *&a, Node *&b)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;

    int carry = 0;
    while (a != NULL || b != NULL || carry != 0)
    {
        int sum = carry;

        if (a != NULL)
        {
            sum += a->data;
            a = a->next;
        }
        if (b != NULL)
        {
            sum += b->data;
            b = b->next;
        }

        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }

    return dummy->next;
}

int main()
{

    Node *node1 = new Node(6);

    // Head
    Node *head1 = node1;
    insertAtHead(head1, 4);
    insertAtHead(head1, 3);
    print(head1);

    cout << "Head 1 : " << head1->data << endl;

    // reverseIterative(head);
    print(head1);

    Node *node2 = new Node(5);

    // Head
    Node *head2 = node2;
    insertAtHead(head2, 6);
    insertAtHead(head2, 4);
    print(head2);
    cout << "Head 2 : " << head2->data << endl;

    Node *add2LLans = add2LL(head1, head2);
    print(add2LLans);

    return 0;
}