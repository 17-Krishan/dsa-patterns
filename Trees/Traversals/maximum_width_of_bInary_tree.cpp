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
 
// TC: O(N)
// SC: O(W) where W is max width

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == nullptr)
            return 0;

        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()) {

            int size = q.size();

            long long minIndex = q.front().second;

            long long first = 0;
            long long last = 0;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                long long cur = q.front().second - minIndex;
                q.pop();

                if(i == 0)
                    first = cur;

                if(i == size - 1)
                    last = cur;

                if(node->left)
                    q.push({node->left, 2 * cur + 1});

                if(node->right)
                    q.push({node->right, 2 * cur + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};