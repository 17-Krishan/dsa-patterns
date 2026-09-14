// Time: O(V + E)
// Space: O(V)

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return count != V;
    }
};