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

// TC: O(n)
// SC: O(h) (height of the tree)

class Node {
public:
    int sum;
    int minVal;
    int maxVal;

    Node(int sum, int minVal, int maxVal) : sum(sum), minVal(minVal), maxVal(maxVal) {}
}; 

class Solution {
    int max_sum = 0;

    Node traverse(TreeNode* root) {
        // Base case: Null nodes are valid BSTs
        if (!root) return Node(0, INT_MAX, INT_MIN);

        Node left = traverse(root->left);
        Node right = traverse(root->right);

        // Check if current subtree forms a valid BST
        if (root->val > left.maxVal && root->val < right.minVal) {
            int current_sum = left.sum + right.sum + root->val;
            max_sum = max(max_sum, current_sum);

            return Node(
                current_sum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            );
        }

        // Return invalid sentinel values if BST condition fails
        return Node(0, INT_MIN, INT_MAX);
    }

public:
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return max_sum;
    }
};