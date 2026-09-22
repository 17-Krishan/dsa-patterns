// Approach: Topological Sort + Relaxation
// Time: O(V + E);
// Space: O(V + E);

class Solution {
  public:
    void dfs(int i, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[i] = 1;
        for(auto& [v, wt]: adj[i]) {
            if(!vis[v]) {
                dfs(v, adj, vis, st);
            }
        }
        st.push(i);
    }
  
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; ++i) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            for(auto& [v, wt]: adj[node]) {
                if(dist[node] != 1e9 && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(auto &x: dist) {
            if(x == 1e9) x = -1;
        }
        
        return dist;
    }
};
