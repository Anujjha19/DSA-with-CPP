
// Remove duplicates in unsorted list using map
#include<bits/stdc++.h>
Node *removeDuplicates(Node *head)
{	
    Node* curr = head;
    Node* prev = NULL;
    unordered_map<int, bool> visited;
    
    while(curr != NULL){
        if(!visited[curr->data]){
            visited[curr->data] = 1;
            prev = curr;
            curr = curr -> next;
        }
        else{
            prev -> next = curr -> next;
            delete curr;
        }
        curr = prev -> next;
    }
    return head;
}


/*= In TC = O(n^2)

Node* removeUnsorted(Node* head){
    Node* curr = head;
    while(curr!=NULL && curr->next != NULL){
        Node* temp = curr;
        while(temp->next!=NULL){
            if(temp->next->data == curr->data){
                Node* next = temp->next;
                temp -> next = temp->next->next;
                delete(next);
            }
            else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
} */