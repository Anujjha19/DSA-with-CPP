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

void solveSumK(Node *root, int &count, int k, vector<int> path)
{
    if (root == NULL)
        return;
    path.push_back(root->data);

    solveSumK(root->left, count, k, path);
    solveSumK(root->right, count, k, path);

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
}

int sumK(Node *root, int k)
{

    int count = 0;
    vector<int> path;

    solveSumK(root, count, k, path);
    return count;
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
