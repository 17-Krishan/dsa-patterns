// Time: O(E log V)
// Space: O(V + E)

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int, int>>> adj(V + 1);
        for(auto & edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, dest});
        vector<int> dist(V + 1, INT_MAX);
        dist[dest] = 0;
        
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            if(d > dist[u]) continue;
            
            for(auto [v, wt] : adj[u]) {
                if(dist[v] > d + wt) {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if(dist[src] == INT_MAX) return {-1};
        
        vector<int> res;
        int node = src;
        res.push_back(src);
        while(node != dest) {
            int nxtNode = -1;
            for(auto [v, wt] : adj[node]) {
                if(dist[v] + wt == dist[node]) {
                    if(nxtNode == -1 || v < nxtNode) {
                        nxtNode = v;
                    }
                }
            }
            node = nxtNode;
            res.push_back(node);
        }
        return res;
    }
};