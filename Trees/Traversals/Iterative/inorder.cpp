#include <bits/stdc++.h>
using namespace std;

// Time  : O(N)
// Space : O(H)

vector<int> inorder(TreeNode* root) {

    vector<int> ans;

    stack<TreeNode*> st;

    TreeNode* curr = root;

    while(curr || !st.empty()) {

        while(curr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->val);

        curr = curr->right;
    }

    return ans;
}#include <bits/stdc++.h>
using namespace std;

vector<int> inorder(TreeNode* root) {

    vector<int> ans;

    stack<TreeNode*> st;

    TreeNode* curr = root;

    while(curr || !st.empty()) {

        while(curr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->val);

        curr = curr->right;
    }

    return ans;
}