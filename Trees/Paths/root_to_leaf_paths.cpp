/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */


// TC : O(N)
// SC : O(H)

class Solution {
  public:
    
    bool isLeaf(Node* node) {
        return (node->left == NULL && node->right == NULL);
    }
    
    void dfs(Node* node, vector<vector<int>> &res, vector<int> &temp) {
        temp.push_back(node->data);
        if(isLeaf(node)) res.push_back(temp);
        if(node->left) dfs(node->left, res, temp);
        if(node->right) dfs(node->right, res, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> res;
        vector<int> temp;
        dfs(root, res, temp);
        return res;
    }
};