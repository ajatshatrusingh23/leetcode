class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
    if (n == 0)
        return -1;
    int m = grid[0].size();

    // Check that the start and target cells are open.
    if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
        return -1;

    // Define the eight possible directions (including diagonals).
    const vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    // Set up the BFS.
    queue<pair<int, int>> q;
    grid[0][0] = 1;  // Mark the starting cell with distance 1.
    q.push({0, 0});

    // Carry out the BFS.
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        int distance = grid[row][col];

        // If we've reached the bottom-right cell, return the distance.
        if (row == n - 1 && col == m - 1)
            return distance;

        // Loop through all valid neighboring cells.
        for (const auto& [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;

            // Check bounds and whether the cell is open (0).
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 0) {
                    
                q.push({newRow, newCol});
                grid[newRow][newCol] = distance + 1;  // Mark cell as visited with updated distance.
            }
        }
    }

    return -1;

    }
};