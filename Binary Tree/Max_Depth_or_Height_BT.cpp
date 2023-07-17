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

int Tree_Depth(Node *root)
{

    if (root == NULL)
        return 0;

    int leftSide = Tree_Depth(root->left);
    int rightSide = Tree_Depth(root->right);

    return (1 + max(leftSide, rightSide));
}
int calculateDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int depth = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
        depth++; // Increase depth after process each level
    }
    return depth;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << " InOrder of Tree ";
    inOrder(root);
    cout << endl;
    cout << " Answer : " << Tree_Depth(root) << endl;

    return 0;
}
