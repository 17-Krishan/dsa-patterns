// Time: O(V + E);
// Space: O(V + E);

class Solution {
public:
    int shortestPath(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(V, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(u == dest)
                return dist[u];

            for(int v : adj[u]) {
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return -1;
    }
};