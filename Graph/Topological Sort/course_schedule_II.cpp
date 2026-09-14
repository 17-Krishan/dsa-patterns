// Time complexity: O(V + E)
// Space complexity: O(V + E)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto &edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if(ans.size() != numCourses)
            return {};

        return ans;
    }
};