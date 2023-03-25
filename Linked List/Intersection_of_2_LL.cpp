#include <bits/stdc++.h>
using namespace std;

// Forward declaration
class Node;

// Node Class
class Node {
public:
    int data;
    Node *next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Inserting at Head
void insertAtHead(Node *&head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Traversing a LL
void print(const Node *head) {
    const Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Returns the length of a LL
int getLength(Node *head) {
    Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Returns the node where two linked lists intersect, if they intersect
Node *getIntersectionNode1(Node *headA, Node *headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    Node *ptrA = headA;
    Node *ptrB = headB;

    // move the longer list's pointer ahead by the difference in length
    if (lenA > lenB) {
        for (int i = 0; i < lenA - lenB; i++) {
            ptrA = ptrA->next;
        }
    } else {
        for (int i = 0; i < lenB - lenA; i++) {
            ptrB = ptrB->next;
        }
    }

    // iterate through both lists until a common node is found
    while (ptrA != nullptr && ptrB != nullptr) {
        if (ptrA == ptrB) {
            return ptrA;
        }
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    // no intersection found
    return nullptr;
}


/*Brute Force
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB){
            ListNode* temp = headA;
            while(temp){
                 // if both Nodes are same
                if(temp == headB){
                    return headB;
                }
                temp = temp -> next;
            }
            headB = headB -> next;
        }
        // intersection is not present between the lists
        return NULL;
    }
 */

/*  Hashing 
node* intersectionPresent(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}
 */
/* 
int getDifference(node* head1,node* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}

node* intersectionPresent(node* head1,node* head2) {
 int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;


}
*/

Node *getIntersectionNode(Node *headA, Node *headB) {
        if( headA == NULL || headB == NULL) return NULL;

        Node * dummy_1 = headA;
        Node * dummy_2= headB;

        while( dummy_1 != dummy_2){
            dummy_1 = dummy_1==NULL ? headB : dummy_1->next;
            dummy_2 = dummy_2==NULL ? headA : dummy_2->next;
        }
        return dummy_1;
    }

int main() {
    // List A
    Node *node1 = new Node(5);
    Node *head1 = node1;
    insertAtHead(head1, 4);
    insertAtHead(head1, 8);
    insertAtHead(head1, 1);
    insertAtHead(head1, 4);

    print(head1);

    // List B
    Node *node2 = new Node(5);
    Node *head2 = node2;
    insertAtHead(head2, 4);
    insertAtHead(head2, 8);
    insertAtHead(head2, 1);
    insertAtHead(head2, 6);
    insertAtHead(head2, 5);

    print(head2);

    Node* ans  = getIntersectionNode( head1 , head2);

    if (ans  == nullptr) {
        cout << "There is no intersection between the two lists." << endl;
    } else {
        cout << "The intersection node data is: " << ans -> data << endl;
    }

    return 0;
}
