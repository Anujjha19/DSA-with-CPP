#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    queue<Node *> q;

    if (root == NULL)
        return ans;
    bool LR = false;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        stack<int> s;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (LR == true)
            {
                ans.push_back(temp->data);
            }
            else
            {
                s.push(temp->data);
            }

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        LR = !LR;
    }
    return ans;
}

vector<int> findSpiral(Node *root)
{
    // Your code here
    vector<int> v;
    int level = 0;
    if (root == NULL)
    {
        return v;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            Node *r = q.front();
            q.pop();
            temp.push_back(r->data);
            if (r->left)
            {
                q.push(r->left);
            }
            if (r->right)
            {
                q.push(r->right);
            }
        }
        if (level % 2 == 0)
        {
            reverse(temp.begin(), temp.end());
        }
        for (int i = 0; i < temp.size(); i++)
        {
            v.push_back(temp[i]);
        }
        level++;
    }
    return v;
}

int main()
{
    // Create the binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> spiralTraversal = findSpiral(root);

    // Print the result
    cout << "Spiral Level Order Traversal: ";
    for (int num : spiralTraversal)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
