// using BFS:

// Time: O(V + E);
// Space: O(V);

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
        queue<pair<int, int>> q;

        q.push({start, -1});
        vis[start] = 1;

        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                }
                else if(neighbor != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(bfs(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};

// using DFS:

// Time: O(V + E);
// Space: O(V);

class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                if(dfs(neighbor, node, adj, vis))
                    return true;
            }
            else if(neighbor != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis))
                    return true;
            }
        }

        return false;
    }
};