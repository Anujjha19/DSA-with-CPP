#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *next;
    int data;
    Node(int d) {
        this->next = NULL;
        this->data = d;
    }
};

class Stack {
public:
    Node *head;
    int max_size; // renamed the data member from size to max_size
    Stack(int size) {
        this->max_size = size; // modified the constructor to update max_size instead of size
        this->head = NULL;
    }
    void push(int val) {
        int cnt = 0;
        Node *temp = head;
        while (temp != NULL) {
            temp = temp->next;
            cnt++;
        }
        if (cnt < max_size) { // updated the condition to check against max_size
            Node *newNode = new Node(val);
            if (head == NULL) {
                head = newNode;
                return;
            } else {
                newNode->next = head;
                head = newNode;
            }
        } else {
            cout << "Stack OverFlow";
        }
    }
    int peak() {
        if (head == NULL) {
            cout << "Stack is Empty";
        } else {
            cout << head->data;
        }
    }
    int pop() {
        if (head == NULL) {
            cout << "Stack UnderFlow";
        } else {
            Node *temp = head;
            cout << " POP element is: " << temp->data;
            head = head->next;
            delete temp;
        }
    }
    bool isEmpty() {
        if (head == NULL)
            return 1;
        else
            return 0;
    }
    int size() {
        int cnt = 0;
        if (head == NULL) {
            cout << "Stack empty";
        } else {
            Node *temp = head;
            while (temp != NULL) {
                temp = temp->next;
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Stack s(5);
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(35);
    s.push(45);
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    s.push(5);
    s.peak();
    s.pop();
    s.peak();
    s.pop();
    s.peak();
    s.pop();
    s.peak();
    s.pop();
    s.peak();
    s.pop();
    s.peak();
    s.pop();
    cout << s.isEmpty() << endl;
    return 0;
}
