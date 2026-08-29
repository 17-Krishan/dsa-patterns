#include <bits/stdc++.h>
using namespace std;

// Time complexity : O(N * M)
// Space complexity : O(N * M)

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return;
        }

        // Water or already visited
        if (grid[row][col] == '0') {
            return;
        }

        // Mark as visited
        grid[row][col] = '0';

        // Explore all 4 directions
        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (grid[row][col] == '1') {
                    islands++;

                    // Mark the entire island as visited
                    dfs(row, col, grid);
                }
            }
        }

        return islands;
    }
};