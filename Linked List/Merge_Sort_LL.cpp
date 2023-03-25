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

Node *OptimizedMiddleNode(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *ans = new Node(4);
    Node *temp = ans;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->next = a;
            temp = a;
            a = a->next;
        }
        else
        {
            temp->next = b;
            temp = b;
            b = b->next;
        }
    }

    // Move remaining nodes to the end
    while (a != NULL)
    {
        temp->next = a;
        temp = a;
        a = a->next;
    }
    while (b != NULL)
    {
        temp->next = b;
        temp = b;
        b = b->next;
    }

    ans = ans->next;

    return ans;
}

Node *mergeSortLL(Node * head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = OptimizedMiddleNode(head);

    Node *left = head;
    Node *right = mid->next;

    mid->next = NULL;

    left = mergeSortLL(left);
    right = mergeSortLL(right);

    Node *mergeBoth = merge(left, right);

    return mergeBoth;
}

int main()
{
    Node *node1 = new Node(70);

    // Head
    Node *head = node1;
    insertAtHead(head, 5);
    insertAtHead(head, 0);
    insertAtHead(head, 10);
    insertAtHead(head, 27);
    insertAtHead(head, 51);
    insertAtHead(head, 77);
    insertAtHead(head, 3);

    cout << "Head " << head->data << endl;

    // reverseIterative(head);
    print(head);

    cout << endl;
    Node *OptimizedAns = OptimizedMiddleNode(head);
    cout << OptimizedAns->data;

    Node *mergeSort = mergeSortLL(head);

    cout << "Sorted linked list: "; // add a space after the colon
    print(mergeSort);               // print the sorted linked list

    return 0;
}

/* #include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* getMiddleNode(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* a, Node* b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    Node* result;
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    }
    else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* mid = getMiddleNode(head);
    Node* nextToMid = mid->next;
    mid->next = NULL;
    Node* left = mergeSort(head);
    Node* right = mergeSort(nextToMid);
    Node* sortedList = merge(left, right);
    return sortedList;
}

int main() {
    Node* node1 = new Node(70);
    Node* head = node1;
    insertAtHead(head, 5);
    insertAtHead(head, 0);
    insertAtHead(head, 10);
    insertAtHead(head, 27);
    insertAtHead(head, 51);
    insertAtHead(head, 77);
    insertAtHead(head, 3);
    cout << "Original linked list: ";
    print(head);
    Node* sortedList = mergeSort(head);
    cout << "Sorted linked list: ";
    print(sortedList);
    return 0;
}
 */