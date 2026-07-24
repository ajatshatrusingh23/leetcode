class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        int ans = 0;
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        while(!q.empty()) {
            auto [row, col, time] = q.front();
            ans = max(ans, time);
            q.pop();
            for (auto [dx, dy] : dirs) {
                if(row + dx  < 0 || row + dx >= m || col + dy < 0 || col + dy >= n) continue;
                if (visited[row + dx][col + dy] || grid[row + dx][col + dy] != 1) continue;
                q.push({row + dx, col + dy, time + 1});
                visited[row + dx][col + dy] = true;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j])  {
                    return -1;
                }
            }
        }
        return ans;
    }
};