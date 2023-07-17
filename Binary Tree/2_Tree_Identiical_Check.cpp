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

bool isSameTree(Node *rootA, Node *rootB)
{
    if (rootA == NULL || rootB == NULL)
    {
        return rootA = rootB;
    }

    return (rootA->data == rootB->data) && (isSameTree(rootA->left, rootB->left)) && (isSameTree(rootA->right, rootB->right));
}

int main()
{
    Node *rootA = new Node(1);
    rootA->left = new Node(2);
    rootA->right = new Node(3);
    rootA->left->left = new Node(4);

    cout << "In-order traversal: ";
    inOrder(rootA);
    cout << endl;

    Node *rootB = new Node(1);
    rootB->left = new Node(2);
    rootB->right = new Node(3);
    rootB->left->left = new Node(4);

    cout << "In-order traversal: ";
    inOrder(rootB);
    cout << endl;

    return 0;
}
