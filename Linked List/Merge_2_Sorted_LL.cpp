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

Node *mergeExtraSpace(Node *list1, Node *list2)
{
    if (!list1)
    {
        return list2;
    }
    if (!list2)
    {
        return list1;
    }

    Node *ans;
    Node *curr;

    if (list1->data <= list2->data)
    {
        ans = list1;
        list1 = list1->next;
    }
    else
    {
        ans = list2;
        list2 = list2->next;
    }
    curr = ans;

    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    if (list1)
    {
        curr->next = list1;
    }
    else
    {
        curr->next = list2;
    }

    return ans;
}

Node *mergeOptimizedSpace(Node *list1, Node *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->data > list2->data)
    {
        swap(list1, list2);
    }
    Node *res = list1;
    while (list1 != NULL && list2 != NULL)

    {
        Node *temp = NULL;
        while (list1 != NULL && list1->data <= list2->data)
        {
            temp = list1;
            list1 = list1->next;
        }

        temp->next = list2;
        swap(list1, list2);
    }

    return res;
}

int main()
{

    Node *node1 = new Node(100);

    // Head
    Node *head1 = node1;
    insertAtHead(head1, 50);
    insertAtHead(head1, 27);
    insertAtHead(head1, 18);
    insertAtHead(head1, 9);
    insertAtHead(head1, 7);
    print(head1);

    cout << "Head 1 : " << head1->data << endl;

    // reverseIterative(head);
    print(head1);

    Node *node2 = new Node(100);

    // Head
    Node *head2 = node2;
    insertAtHead(head2, 88);
    insertAtHead(head2, 62);
    insertAtHead(head2, 27);
    insertAtHead(head2, 18);
    insertAtHead(head2, 6);
    print(head2);
    cout << "Head 2 : " << head2->data << endl;

    // Node *ans = mergeExtraSpace(head1, head2);
    // print(ans);
    Node *ans = mergeOptimizedSpace(head1, head2);
    print(ans);

    return 0;
}