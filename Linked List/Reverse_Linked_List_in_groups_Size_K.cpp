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
/* node* reverseKNodes(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;

    int length = lengthOfLinkedList(head);

    node* dummyHead = new node(0);
    dummyHead->next = head;

    node* pre = dummyHead;
    node* cur;
    node* nex;

    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
}
 */

Node *reverseKNodes(Node *&head, int k)
{

    if (head == NULL)
        return NULL;

    // reverse first k nodes
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    Node *temp = head;
    int count = 0;

    // count remaining nodes
    int countNodes = 0;
    while (temp != NULL)
    {
        countNodes++;
        temp = temp->next;
    }

    if (countNodes >= k)
    {
        while (curr != NULL && count < k)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if (forward != NULL)
        {
            head->next = reverseKNodes(forward, k);
        }
    }
    else
    {
        return head;
    }

    return prev;
}

int main()
{

    Node *head = NULL;
    int k = 2;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);
    insertAtHead(head, 7);
    // insertAtHead(head, 8);

    cout << "Original Linked List: ";
    print(head);
    cout << "After Reversal of k Nodes: ";
    Node *newHead = reverseKNodes(head, k);
    print(newHead);
    return 0;
}