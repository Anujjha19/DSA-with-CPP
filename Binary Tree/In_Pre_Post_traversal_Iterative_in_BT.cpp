#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        root = s.top();
        s.pop();
        cout << root->data << " ";

        if (root->right != NULL)
        {
            s.push(root->right);
        }
        if (root->left != NULL)
        {
            s.push(root->left);
        }
    }
}

void inOrder(Node *root)
{
    stack<Node *> s;

    while (!s.empty() || root != NULL)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top();
            s.pop();
            cout << root->data << " ";
            root = root->right;
        }
    }
}

void postOrder_2_STACKS(Node *root)
{
    stack<Node *> s1, s2;

    if (root == NULL)
        return;

    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left != NULL)
        {
            s1.push(root->left);
        }
        if (root->right != NULL)
        {
            s1.push(root->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}
// 1 stacks pending

void postOrder(Node *root)
{
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << " Root of Tree " << root->data << endl;
    cout << endl
         << "IN-ORDER : ";
    inOrder(root);
    cout << endl
         << "PRE-ORDER : ";
    preOrder(root);
    cout << endl
         << "POST-ORDER : ";
    postOrder(root);

    return 0;
}
