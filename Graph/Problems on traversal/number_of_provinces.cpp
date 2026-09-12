#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(N^2)
// Space complexity : O(N)

class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node] = 1;

        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
            if (isConnected[node][neighbour] == 1 && !visited[neighbour]) {
                dfs(neighbour, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);

        int provinces = 0;

        for (int city = 0; city < n; city++) {
            if (!visited[city]) {
                provinces++;
                dfs(city, isConnected, visited);
            }
        }

        return provinces;
    }
};