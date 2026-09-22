// Time complexity: O((MxN)log(MxN))
// Space complexity: O(MxN)

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> diff(n, vector<int> (m, 1e9));
        pq.push({0, {0, 0}});
        diff[0][0] = 0; 

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        while(!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            if(r == n - 1 && c == m - 1) return d;
            pq.pop();
            if(d > diff[r][c]) continue;

            for(int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && max(d, abs(h[nr][nc] - h[r][c])) < diff[nr][nc]) {
                    diff[nr][nc] = max(d, abs(h[nr][nc] - h[r][c]));
                    pq.push({diff[nr][nc], {nr, nc}});
                }
            }

        }
        return -1;
    }
};