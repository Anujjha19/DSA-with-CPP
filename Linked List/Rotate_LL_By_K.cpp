#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int a)
    {
        num = a;
        next = NULL;
    }
};
// utility function to insert node at the end of the list
void insertNode(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}
// utility function to print list
void printList(node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
    return;
}

// utility function to rotate list by k times
node *rotateRightBF(node *head, int k)
{
    if (head == NULL || head->next == NULL)
        return head;
    for (int i = 0; i < k; i++)
    {
        node *temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;
            
        node *end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
} /* Time Complexity: O(Number of nodes present in the list*k)
 Reason: For k times, we are iterating through the entire list to get the last element and move it to first.
 Space Complexity: O(1)
 Reason: No extra data structures is used for computations */

node *rotateRight(node *head, int k)
{   
    if( head ==NULL || head -> next == NULL || k==0){
        return head;
    }

//Length of List
    node*temp = head ;
    int length =   1;
    while( temp -> next != NULL){
        ++length;
        temp = temp ->next;
    }

    //Last node to first node
    temp ->next = head;
    
    k = k% length ; //Length of list is samller then K

    int end = length-k;
    while(end--) temp = temp ->next;

    //Last Node Break

    head = temp -> next;
    temp -> next = NULL;

    return head;

}
/* Time Complexity: O(length of list) + O(length of list – (length of list%k))
Reason: O(length of the list) for calculating the length of the list. O(length of the list – (length of list%k)) for breaking link.

Space Complexity: O(1
Reason: No extra data structure is used for computation. */

int main()
{
    node *head = NULL;
    // inserting Node
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    node *newHead = rotateRight(head, k); // calling function for rotating right of the nodes by k times

    cout
        << "After " << k << " iterations: ";
    printList(newHead); // list after rotating nodes
    return 0;
}
