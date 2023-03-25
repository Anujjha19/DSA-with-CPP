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
void insertNode(Node *&head, int data)
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
/*  // Linked List to Vector Then Check 

    bool checkPalindrome(vector <int> arr){
        int n=arr.size();
        int s=0;
        int e=n-1;
        
        while(s<=e){
            if(arr[s] != arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    
        bool isPalindrome(Node *head)
        {
            vector <int> arr;
            Node* temp=head;
            while( temp !=NULL){
                arr.push_back(temp -> data);
                temp= temp -> next;
            }
            return checkPalindrome(arr);
        }
};
 */

Node* reverse( Node* &head){
    Node * prev = NULL;
    Node* next = NULL;

    while( head != NULL ){
        next = head -> next;
        head -> next = prev;
        prev = head ; 
        head = next ;
    }
    return prev;
}


    bool isPalindrome(Node* head) {
        if( head == NULL || head -> next == NULL) return true;

        Node* slow = head;
        Node* fast = head ;

        while( fast -> next != NULL && fast -> next -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        slow -> next = reverse( slow -> next );
        slow = slow -> next ;
        

        fast = head ;// As Dummy Node Node Dummy = head ;

        while( slow != NULL){

            if( fast -> data != slow -> data) return false;
            else
            slow = slow -> next ;
            fast = fast -> next;
        }
            return true;
    }

int main()
{
    //Node *node = new Node(6);

    // Head
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);
    //insertNode(head, 8);
    print(head);

    cout << "Head 1 : " << head->data << endl;

    // reverseIterative(head);
    print(head);

    isPalindrome(head) ? cout << "True" : cout << "False";
    return 0;
}

