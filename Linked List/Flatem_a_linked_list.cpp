#include <iostream>
#include <queue>

using namespace std;

// Linked list Node
struct Node {
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};


void print(Node* root) {
        if (root == nullptr) {
        cout << "Empty List\n";
        return;
    }
    while (root != nullptr) {
        Node* curr = root;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->bottom;
        }
        root = root->next;
        cout << endl;
    }
}


Node* merge2List ( Node* a , Node* b){
        Node* temp = new Node(0);
        Node* res = temp ;
        
        while( a!= NULL && b!= NULL){
            if( a-> data < b-> data){
                temp = temp -> bottom = a;
                a = a-> bottom;
            }
            else{
                temp = temp -> bottom = b;
                b = b-> bottom;
            }
        }
        if( a) temp -> bottom = a;//a = a-> bottom;
            
        else
            temp -> bottom =b;  // b = b -> bottom;
            
    
        return res -> bottom;
    }
    
    
    
Node *flatten(Node *root)
{   
    if( root == NULL || root -> next == NULL)return root;
    
    root -> next = flatten( root -> next);
    
    root = merge2List(root , root -> next);
    
    return root ;
    
}

int main() {
    // This code builds the flattened linked list
    // of first picture in this article ;
    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->next = new Node(10);
    head->next->bottom = new Node(20);
    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);
    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

print(head);
    // Function call
    flatten(head);
    cout << endl;
print(head);

    return 0;
}




/* #include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};

// Flattens the given linked list and prints the flattened list
void flatten(Node* root) {
    priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> pq([](Node* a, Node* b) {
        return a->data > b->data;
    });

    while (root != nullptr) {
        pq.push(root);
        root = root->next;
    }

    while (!pq.empty()) {
        Node* curr = pq.top();
        pq.pop();
        cout << curr->data << " ";
        if (curr->bottom != nullptr) {
            pq.push(curr->bottom);
        }
    }
}

int main() {
    int num_heads = 4;
    vector<int> lengths = {4, 2, 3, 4};
    vector<int> elements = {5, 7, 8, 30, 10, 20, 19, 22, 50, 28, 35, 40, 45};

    // Build the linked list
    vector<Node*> heads(num_heads, nullptr);
    int idx = 0;
    for (int i = 0; i < num_heads; i++) {
        int len = lengths[i];
        for (int j = 0; j < len; j++) {
            int val = elements[idx++];
            Node* node = new Node(val);
            if (j == 0) {
                heads[i] = node;
            } else {
                Node* prev = heads[i];
                while (prev->bottom != nullptr) {
                    prev = prev->bottom;
                }
                prev->bottom = node;
            }
        }
    }
    for (int i = 0; i < num_heads - 1; i++) {
        heads[i]->next = heads[i + 1];
    }

    // Flatten and print the linked list
    flatten(heads[0]);

    return 0;
}
 */