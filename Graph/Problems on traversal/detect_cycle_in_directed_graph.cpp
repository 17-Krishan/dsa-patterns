#include<bits/stdc++.h>
using namespace std;

// Time complexity: O(V + E)
// Space complexity: O(V)

// can also be solved using Kahn's Algorithm

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis) {

        vis[node] = 1;
        pathVis[node] = 1;

        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                if(dfs(neighbor, adj, vis, pathVis))
                    return true;
            }
            else if(pathVis[neighbor]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis))
                    return true;
            }
        }

        return false;
    }
};