/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

// TC : O(N log N) - due to map (if Unordered map is used then O(N))
// SC : O(N)

// Here, we can not use dfs, as we want the nodes that are at minimum depth from the root for each horizontal distance

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> res;
        map<int, int> nodes;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            Node* node = q.front().first;
            int col = q.front().second;
            q.pop();
            if(nodes.find(col) == nodes.end()) nodes[col] = node->data;
            if(node->left) q.push({node->left, col-1});
            if(node->right) q.push({node->right, col+1});
        }
        for(auto &col: nodes) {
            res.push_back(col.second);
        }
        return res;
    }
};