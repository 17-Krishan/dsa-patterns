/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// TC : O(N)
// SC : O(H) 

class Solution {
public:

    int pathSum(TreeNode* node, int &res) {
        if(node == NULL) return 0;
        int lps = max(0, pathSum(node->left, res));
        int rps = max(0, pathSum(node->right, res));
        res = max(res, node->val+lps+rps);
        return node->val + max(lps, rps);
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        pathSum(root, res);
        return res;
    }
};