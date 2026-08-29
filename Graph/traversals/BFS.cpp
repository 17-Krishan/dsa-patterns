#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(V + E)
// Space complexity : O(V)

class Solution {
public:
    vector<int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> visited(n, 0);
        vector<int> traversal;

        queue<int> q;

        visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            traversal.push_back(node);

            for (int neighbour : adj[node]) {
                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return traversal;
    }
};