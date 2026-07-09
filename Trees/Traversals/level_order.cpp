#include <bits/stdc++.h>
using namespace std;

/*
Level Order Traversal
Time  : O(N)
Space : O(W)
W = Maximum width of the tree
Worst Case : O(N)
*/

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrder(TreeNode* root) {

    if(root == nullptr)
        return;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()) {

        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if(node->left)
            q.push(node->left);

        if(node->right)
            q.push(node->right);
    }
}

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    levelOrder(root);

    return 0;
}