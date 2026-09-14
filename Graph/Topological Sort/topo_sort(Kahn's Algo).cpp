// Kahn's Algorithm (BFS)

// Time: O(V + E)
// Space: O(V)

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(int neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return ans;
    }
};


// using DFS

// Time: O(V + E)
// Space: O(V)

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, stack<int>& st) {

        vis[node] = 1;

        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                dfs(neighbor, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        stack<int> st;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

