/* Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node)
 */

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

void solve(Node *root, int len, int &maxlen, int sum, int &maxSum)
{
    if (root == NULL)
    {
        if (len == maxlen)
        {
            maxSum = max(sum, maxSum);
        }
        else if (len > maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left, len + 1, maxlen, sum, maxSum);
    solve(root->right, len + 1, maxlen, sum, maxSum);
}

int sumOfLongRootToLeafPath(Node *root)
{
    if (root == NULL)
    {
        return 0; // Return 0 for an empty tree
    }
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, len, maxlen, sum, maxSum);
    return maxSum;
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
