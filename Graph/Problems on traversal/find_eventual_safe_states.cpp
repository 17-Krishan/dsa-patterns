// Time: O(V + E)
// Space: O(V)

class Solution {
public:
    bool dfs(int start, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& safe) {
        vis[start] = 1;
        pathVis[start] = 1;
        for(int& neighbour : graph[start]) {
            if(pathVis[neighbour] ||!safe[neighbour]) {
                safe[start] = 0;
                return true;
            }
            if(!vis[neighbour]) {
                if(dfs(neighbour, graph, vis, pathVis, safe)) {
                    safe[start] = 0;
                    return true;
                };
            }
        }
        pathVis[start] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), safe(n, 1);
        for(int i = 0; i < n; ++i) {
            if(!vis[i]) {
                dfs(i, graph, vis, pathVis, safe);
            }
        }
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            if(safe[i]) res.push_back(i);
        }
        return res;
    }
};