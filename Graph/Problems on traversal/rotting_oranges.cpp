// Time  = O(N × M)
// Space = O(N × M)

// multi-source BFS.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int sz = q.size();
            bool rotten = false;

            while(sz--) {
                auto [x, y] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx >= 0 && nx < n &&
                       ny >= 0 && ny < m &&
                       grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                        rotten = true;
                    }
                }
            }

            if(rotten)
                time++;
        }

        if(fresh > 0)
            return -1;

        return time;
    }
};