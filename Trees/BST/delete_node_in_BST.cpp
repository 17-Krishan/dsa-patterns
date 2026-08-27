#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// TC: O(log n) (worst case: O(n) --> skewed tree)
// SC: O(1)

class Solution {
private:
    // Helper function to handle deletion of a node given its pointer
    TreeNode* deleteTargetNode(TreeNode* target) {
        if (target->left == nullptr) return target->right;
        if (target->right == nullptr) return target->left;

        // Node has 2 children:
        // Find the rightmost node in the left subtree (In-order Predecessor)
        TreeNode* rightmostInLeft = target->left;
        while (rightmostInLeft->right != nullptr) {
            rightmostInLeft = rightmostInLeft->right;
        }

        // Attach target's original right subtree to the right of the predecessor
        rightmostInLeft->right = target->right;

        // Return the root of the restructured subtree
        return target->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        // Case: The node to delete is the root itself
        if (root->val == key) {
            TreeNode* newRoot = deleteTargetNode(root);
            delete root; // Free memory
            return newRoot;
        }

        TreeNode* curr = root;
        
        // Search for the node while preserving parent reference
        while (curr != nullptr) {
            if (key < curr->val) {
                if (curr->left != nullptr && curr->left->val == key) {
                    TreeNode* toDelete = curr->left;
                    curr->left = deleteTargetNode(toDelete);
                    delete toDelete; // Free memory
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right != nullptr && curr->right->val == key) {
                    TreeNode* toDelete = curr->right;
                    curr->right = deleteTargetNode(toDelete);
                    delete toDelete; // Free memory
                    break;
                }
                curr = curr->right;
            }
        }

        return root;
    }
};