/* #include <bits/stdc++.h>
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

int main()
{
    Node *root = new Node(5);
    root->left = new Node(15);
    root->right = new Node(7);
    root->right->right = new Node(-10);
    root->right->right->right = new Node(4);

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
 */

#include <bits/stdc++.h>

using namespace std;
int dfs(vector<vector<int>>& tree, vector<int>& values, int node, int& max_sum) {
    int current_sum = values[node];
    
    for (int child : tree[node]) {
        int child_sum = dfs(tree, values, child, max_sum);
        
        if (child_sum > 0) {
            current_sum += child_sum;
        }
    }
    
    max_sum = max(max_sum, current_sum);
    
    return current_sum;  // Return current_sum instead of max(current_sum, 0)
}

int bestSumDownwardTreePath(vector<int>& parent, vector<int>& values) {
    int n = parent.size();
    
    vector<vector<int>> tree(n);
    
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            tree[parent[i]].push_back(i);
        }
    }
    
    int max_sum = INT_MIN;
    dfs(tree, values, 0, max_sum);
    
    return max_sum;
}

int main() {
    vector<int> parent = {-1, 0, 1, 1, 0};
    vector<int> values = {5, 7, -10, 4, 15};
    
    cout << bestSumDownwardTreePath(parent, values) << endl;  // Output: 20
    
    return 0;
}