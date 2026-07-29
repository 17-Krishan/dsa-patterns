/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

// TC - O(N)
// SC - O(H)

class Solution {
public:

    bool isLeaf(TreeNode* node) {
        return node && node->left == nullptr && node->right == nullptr;
    }

    void addLeftBoundary(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->left;

        while(curr) {
            if(!isLeaf(curr))
                ans.push_back(curr->val);

            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(TreeNode* root, vector<int>& ans) {
        if(root == nullptr)
            return;

        if(isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRightBoundary(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root->right;
        vector<int> temp;

        while(curr) {
            if(!isLeaf(curr))
                temp.push_back(curr->val);

            if(curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        reverse(temp.begin(), temp.end());

        for(int x : temp)
            ans.push_back(x);
    }

    vector<int> boundaryTraversal(TreeNode* root) {

        vector<int> ans;

        if(root == nullptr)
            return ans;

        if(!isLeaf(root))
            ans.push_back(root->val);

        addLeftBoundary(root, ans);

        addLeaves(root, ans);

        addRightBoundary(root, ans);

        return ans;
    }
};