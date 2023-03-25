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
bool findNode(Node *&head, int x)
{
    if (head == NULL)
        return false;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == x)
            return true;
        else
            temp = temp->next;
    }
    return false;
}
bool FindNodeRecursively(Node *&head, int x)
{
    if (head == NULL)
        return false;

    if (head->data == x)
        return true;

    return FindNodeRecursively(head->next, x);
}

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

    int x = 90;
    findNode(head, x) ? cout << "YES" : cout << "NO";

    FindNodeRecursively(head, x) ? cout << "YES" : cout << "NO";
    return 0;
}