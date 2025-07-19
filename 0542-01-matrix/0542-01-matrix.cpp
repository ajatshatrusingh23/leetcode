class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
    int c = mat[0].size();

    queue<pair<int, int>> q;

    // Step 1: Push all 0s into the queue and mark 1s as INF
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
            } else {
                mat[i][j] = 1e9; // treat 1 as unvisited
            }
        }
    }

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    // Step 2: BFS
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (x >= 0 && y >= 0 && x < r && y < c) {
                if (mat[x][y] > mat[i][j] + 1) {
                    mat[x][y] = mat[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    return mat;

    }
};