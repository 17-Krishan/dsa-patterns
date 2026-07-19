#include <bits/stdc++.h>
using namespace std;

// Time  : O(N)
// Space : O(H)

vector<int> postorder(TreeNode* root) {

    vector<int> ans;

    stack<TreeNode*> st;

    TreeNode* curr = root;
    TreeNode* lastVisited = nullptr;

    while(curr || !st.empty()) {

        if(curr) {
            st.push(curr);
            curr = curr->left;
        }
        else {

            TreeNode* node = st.top();

            if(node->right &&
               lastVisited != node->right) {

                curr = node->right;
            }
            else {

                ans.push_back(node->val);

                lastVisited = node;

                st.pop();
            }
        }
    }

    return ans;
}