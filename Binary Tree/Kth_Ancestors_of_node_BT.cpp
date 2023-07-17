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

bool solve(Node *root, int &k, int node, int &ans)
{

    if (!root)
        return false;
    if (root->data == node)
        return true;

    if (solve(root->left, k, node, ans) == true)
    {
        k--;
        if (k == 0)
            ans = root->data;
        return true;
    }
    if (solve(root->right, k, node, ans) == true)
    {
        k--;
        if (k == 0)
            ans = root->data;
        return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
        int ans{-1};
        if( root == NULL || root ->data == node ) return ans;
    solve(root, k, node, ans);
    return ans;
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
