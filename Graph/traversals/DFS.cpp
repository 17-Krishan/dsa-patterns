#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(V + E)
// Space complexity : O(V)

class Solution {
public:
    void dfsHelper(
        int node,
        vector<vector<int>>& adj,
        vector<int>& visited,
        vector<int>& traversal
    ) {
        visited[node] = 1;
        traversal.push_back(node);

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfsHelper(neighbour, adj, visited, traversal);
            }
        }
    }

    vector<int> dfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> visited(n, 0);
        vector<int> traversal;

        dfsHelper(start, adj, visited, traversal);

        return traversal;
    }
};