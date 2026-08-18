#include <iostream>
#include <vector>

using namespace std;

// ------------------------------------------------------
// Time: O(N)
// Space: O(1)
// ------------------------------------------------------

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> morrisInorder(Node* root) {
    vector<int> inorder;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // No left child: process current node and move right
            inorder.push_back(curr->data);
            curr = curr->right;
        } else {
            // Find the in-order predecessor (rightmost node in left subtree)
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                // Create a temporary thread to the current node
                prev->right = curr;
                curr = curr->left;
            } else {
                // Thread already exists: remove it, process node, move right
                prev->right = nullptr;
                inorder.push_back(curr->data); // Process Root
                curr = curr->right;
            }
        }
    }

    return inorder;
}