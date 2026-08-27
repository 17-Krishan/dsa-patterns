#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// TC: O(log n) (worst case: O(n))
// SC: O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (p->val < curr->val && q->val < curr->val) {
                // Both nodes lie in the left subtree
                curr = curr->left;
            } else if (p->val > curr->val && q->val > curr->val) {
                // Both nodes lie in the right subtree
                curr = curr->right;
            } else {
                // Split point found (one node on left, one on right, or one is curr)
                return curr;
            }
        }
        return nullptr;
    }
};