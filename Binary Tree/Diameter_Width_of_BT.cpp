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

int inOrder_Depth(Node *root)
{
    if (root == NULL)
        return 0;
    int leftSide = inOrder_Depth(root->left);
    int rightSide = inOrder_Depth(root->right);
    return (1 + max(leftSide, rightSide));
}

int Diameter_of_tree_Nsquare(Node *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    int left = inOrder_Depth(root->left);
    int right = inOrder_Depth(root->right);

    ans = max(ans, left + right);

    int leftDiameter = Diameter_of_tree_Nsquare(root->left);
    int rightDiameter = Diameter_of_tree_Nsquare(root->right);

    return max(ans, max(leftDiameter, rightDiameter));
}
int height(Node *root, int &d)
{
    if (root == NULL)
        return 0;
    int left = height(root->left, d);
    int right = height(root->right, d);
    d = max(d, left + right);     

    return (1 + max(left, right));
}

int Diameter_of_tree(Node *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
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

    cout << " Diameter / Width " << inOrder_Depth(root) << endl;

    return 0;
}
