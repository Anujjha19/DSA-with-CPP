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

Node *Delete_Nth_node(Node *&head, int n)
{
    int len = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }

    if (n > len)
    { // edge case
        return head;
    }
    int pos = len - n; // position of Nth node from the beginning
    if (pos == 0)
    { // edge case
        return head->next;
    }
    curr = head;
    for (int i = 0; i < pos - 1; i++)
    {
        // traverse to (N-1)th node
        curr = curr->next;
    }
    curr->next = curr->next->next; // remove Nth node
    return head;
}

Node *Optimized_Delete_Nth_node(Node *&head, int n)
{
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if (fast == NULL)
    {
        head = head->next;
        return head;
    }
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = slow->next->next;
    temp->next = NULL;
    delete temp;

    return head;
}

int main()
{

    Node *node1 = new Node(6);

    // Head
    Node *head = node1;
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    print(head);

    cout << "Head " << head->data << endl;

    // reverseIterative(head);
    print(head);

    // Node *ans = Delete_Nth_node(head,2 );
    // print(ans);

    Node *Optimized_Ans = Optimized_Delete_Nth_node(head, 2);
    print(Optimized_Ans);

    return 0;
}