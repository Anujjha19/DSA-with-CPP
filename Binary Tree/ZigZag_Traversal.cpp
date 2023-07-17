#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    bool LR = true; // flag to indicate the direction
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            // Determine the index based on the direction
            int index = LR ? i : size - i - 1;
            level[index] = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        result.push_back(level);
        LR = !LR; // toggle the direction for the next level
    }
    return result;
}
void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    // Before: Create a binary tree
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Print the binary tree
    printTree(root);

    // Call the zigzagLevelOrder function
    vector<vector<int>> traversal = zigzagLevelOrder(root);

    // After: Print the result
    for (const auto &level : traversal)
    {
        for (const auto &value : level)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}