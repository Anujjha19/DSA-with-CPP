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

void inOrder(Node *root)
{

    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{

    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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
