#include <iostream>
#include <cmath>
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

int calculateDepth(Node *root)
{
    if (root == nullptr)
        return 0;
    int leftSide = calculateDepth(root->left);
    int rightSide = calculateDepth(root->right);

    return (1 + max(leftSide, rightSide));
}

bool checkBalance_Nsquare_(Node *root)
{
    if (root == nullptr)
        return true;

    int LH = calculateDepth(root->left);
    int RH = calculateDepth(root->right);
    int Diff = abs(LH - RH);

    if (Diff > 1)
        return false;
    bool left = checkBalance_Nsquare_(root->left);
    bool right = checkBalance_Nsquare_(root->right);
    if (!left || !right)
        return false;

    return true;
}

int height_Optimized_ans(Node *root)
{
    if (root == nullptr)
        return 0;

    int leftSide = height_Optimized_ans(root->left);
    if (leftSide == -1)
        return -1;

    int rightSide = height_Optimized_ans(root->right);
    if (rightSide == -1)
        return -1;

    if (abs(leftSide - rightSide) > 1)
        return -1;

    return (1 + max(leftSide, rightSide));
}

bool checkBalance(Node *root)
{
    return height_Optimized_ans(root) != -1;
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

    bool isBalanced = checkBalance(root);
    cout << "Is Tree Balanced: " << (isBalanced ? "Yes" : "No") << endl;

    return 0;
}
