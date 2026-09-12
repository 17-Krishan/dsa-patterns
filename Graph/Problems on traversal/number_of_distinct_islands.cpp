// Time: O(N * M log(N * M));
// Space: O(N * M);

class Solution {
public:
    int n, m;

    void dfs(int i, int j, int basei, int basej, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& shape) {

        vis[i][j] = 1;

        shape.push_back({i - basei, j - basej});

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for(int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == 1 && !vis[ni][nj]) {
                dfs(ni, nj, basei, basej, grid, vis, shape);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {

                    vector<pair<int,int>> shape;

                    dfs(i, j, i, j, grid, vis, shape);

                    st.insert(shape);
                }
            }
        }

        return st.size();
    }
};