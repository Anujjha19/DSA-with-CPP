#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void inOrder(Node *root)
{
    if (root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *lca(Node *root, int n1, int n2)
{
    // Your code here

    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    else if (left != NULL && right == NULL)
    {
        return left;
    }
    else if (left == NULL && right != NULL)
    {
        return right;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
