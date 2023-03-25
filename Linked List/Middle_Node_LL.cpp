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
int getlength(Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return len;
}
Node *MiddleNode(Node *head)
{
    int len = getlength(head);
    int ans = (len / 2);
    Node *temp = head;
    int cnt = 0;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }

    return temp;
}

Node *OptimizedMiddleNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

/* ListNode* middleNode(ListNode* head) {
        ListNode* fast = head ;
        ListNode* slow = head ;

        while( fast != NULL &&fast-> next!= NULL ){
            fast = fast ->next->next;

        slow = slow->next;
    }
    return slow;
    } */
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

    int ans = getlength(head);

    Node *Middle = MiddleNode(head);
    cout << Middle->data;
    cout << endl;
    Node *OptimizedAns = OptimizedMiddleNode(head);
    cout << OptimizedAns->data;

    return 0;
}