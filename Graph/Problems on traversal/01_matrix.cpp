// Time: O(m * n);
// Space: O(m * n);

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int> (n, 0));

        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(mat[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }

        int dist = 0;
        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {-1, 0, 1, 0};
        while(!q.empty()) {
            dist++;
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                auto [row, col] = q.front();
                q.pop();
                for(int j = 0; j < 4; ++j) {
                    int nrow = row + delRow[j];
                    int ncol = col + delCol[j];
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                        res[nrow][ncol] = dist;
                    }
                }
            }
        }
        return res;
    }
};