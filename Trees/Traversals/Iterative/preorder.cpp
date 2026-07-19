#include <bits/stdc++.h>
using namespace std;

// Time  : O(N)
// Space : O(H) average
// Worst : O(N)
// H -> height of the tree

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

vector<int> preorder(TreeNode* root) {

    vector<int> ans;

    if(root == nullptr)
        return ans;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {

        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->val);

        if(node->right)
            st.push(node->right);

        if(node->left)
            st.push(node->left);
    }

    return ans;
}