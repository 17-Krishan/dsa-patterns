// ------------------------------------------------------
// Using recursive DFS

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

// TC : O(N)
// SC : O(H) = O(N)

class Solution {
public:

    void dfs(TreeNode* root, int level, vector<int>& res) {
        if(root == nullptr)
            return;

        if(level == res.size())
            res.push_back(root->val);

        dfs(root->right, level + 1, res);
        dfs(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};


// -----------------------------------------------------------------
// Using iterative level order traversal

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

// TC : O(N)
// SC : O(W) = O(N)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if(root == nullptr)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(i == size - 1)
                    res.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }
        }

        return res;
    }
};