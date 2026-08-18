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

vector<int> morrisPreorder(Node* root) {
    vector<int> preorder;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // No left child: process current node and move right
            preorder.push_back(curr->data);
            curr = curr->right;
        } else {
            // Find the predecessor (rightmost node in left subtree)
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                // Process node BEFORE visiting left subtree
                preorder.push_back(curr->data); // Process Root
                prev->right = curr;             // Create thread
                curr = curr->left;
            } else {
                // Thread exists: remove it and move right
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return preorder;
}