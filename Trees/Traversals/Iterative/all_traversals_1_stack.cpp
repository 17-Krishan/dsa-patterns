#include <bits/stdc++.h>
using namespace std;

// Time  : O(N)
// Space : O(H)
// Worst : O(N)
// H -> height of the tree

vector<vector<int>> allTraversals(TreeNode* root) {

    vector<int> pre, in, post;

    if(root == nullptr) return {in, pre, post};

    stack<pair<TreeNode*,int>> st;

    st.push({root,1});

    while(!st.empty()) {

        auto [node,num] = st.top();

        st.pop();

        if(num == 1) {

            pre.push_back(node->val);

            st.push({node,2});

            if(node->left)
                st.push({node->left,1});
        }
        else if(num == 2) {

            in.push_back(node->val);

            st.push({node,3});

            if(node->right)
                st.push({node->right,1});
        }
        else {

            post.push_back(node->val);
        }
    }

    return {in, pre, post};
}