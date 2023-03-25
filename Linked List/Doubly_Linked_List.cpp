#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
            // this->prev = NULL;
        }
    }
};
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

// Length of a DLL
int getLength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
// Insertion
void inserionAt_Head_inDLL(Node *&head, Node *tail, int data)
{
    // Solvig Exception if There are NO nodes
    if (head == NULL)
    {
        Node *temp = new Node(data);
        temp = head;
        temp = tail;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void inserionAt_Tail_inDLL(Node *&tail2, Node *&head2, int data)
{
    if (tail2 == NULL)
    {
        Node *temp = new Node(data);
        temp = tail2;
        temp = head2;
    }
    else
    {
        Node *temp = new Node(data);
        tail2->next = temp;
        temp->prev = tail2;
        tail2 = temp;
    }
}
void inserionAt_Position_inDLL(Node *&head3, Node *&tail3, int data, int position)
{
    // solving First Node Case
    if (position == 1)
    {
        inserionAt_Head_inDLL(head3, tail3, data);
        return;
    }
    Node *temp = head3;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // Solving Last Node
    if (temp->next == NULL)
    {
        inserionAt_Tail_inDLL(tail3, head3, data);
    }

    Node *Insert = new Node(data);
    Insert->next = temp->next;
    temp->next->prev = Insert;
    temp->next = Insert;
    Insert->prev = temp;
}

void Deletion_DLL(Node *&head3, Node *&tail3, int position)
{

    if (position == 1)
    {
        Node *temp1 = head3;
        temp1->next->prev = NULL;
        head3 = temp1->next;
        temp1->next = NULL;
        delete temp1;
    }
    else // Middle and Last Node Delete
    {
        Node *curr = head3;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        // Placing Tail at it's right postion
        Node *temp1 = tail3;
        tail3 = curr->prev;
    }
}

int main()
{

    Node *node = new Node(100);

    Node *head = node;
    Node *tail = node;

    /*  Node *head = NULL;
     Node *tail = NULL; */
    print(head);
    // Head Insert
    inserionAt_Head_inDLL(head, tail, 4);
    print(head);
    inserionAt_Head_inDLL(head, tail, 200);
    print(head);
    inserionAt_Head_inDLL(head, tail, 1);
    print(head);
    cout << "Length of a LL : " << getLength(head) << endl;
    // cout << head->data << " ";
    // cout << tail->data;

    // Tail Insert
    Node *head2 = node;
    Node *tail2 = node;

    inserionAt_Head_inDLL(head2, tail2, 5000);
    print(head2);

    inserionAt_Tail_inDLL(tail2, head2, 1000);
    print(head2);

    // Insert at Middle

    Node *head3 = node;
    Node *tail3 = node;

    inserionAt_Head_inDLL(head3, tail3, 101);
    print(head3);

    inserionAt_Tail_inDLL(tail3, head3, 201);
    print(head3);

    inserionAt_Position_inDLL(head3, tail3, 301, 2);
    print(head3);
    inserionAt_Position_inDLL(head3, tail3, 401, 4);
    print(head3);

    Deletion_DLL(head3, tail3, 2);
    print(head3);
    Deletion_DLL(head3, tail3, 1);
    print(head3);
    Deletion_DLL(head3, tail3, 3);
    print(head3);

    return 0;
}