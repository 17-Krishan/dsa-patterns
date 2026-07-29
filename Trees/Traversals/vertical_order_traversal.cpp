// TC : O(N log(N))
// SC : O(N)

class Solution {
public:

    void preorder(TreeNode* root, int col, int level,
                  map<int, map<int, multiset<int>>> &mp) {

        if(root == nullptr) return;

        mp[col][level].insert(root->val);

        preorder(root->left, col - 1, level + 1, mp);
        preorder(root->right, col + 1, level + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> res;
        if(root == nullptr) return res;

        map<int, map<int, multiset<int>>> mp;

        preorder(root, 0, 0, mp);

        for(auto &col : mp) {
            vector<int> temp;

            for(auto &level : col.second) {
                for(int val : level.second)
                    temp.push_back(val);
            }

            res.push_back(temp);
        }

        return res;
    }
};