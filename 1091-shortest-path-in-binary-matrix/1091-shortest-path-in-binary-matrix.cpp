class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
    if (n == 0)
        return -1;
    int m = grid[0].size();

  
    if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
        return -1;
 
    const vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

     
    queue<pair<int, int>> q;
    grid[0][0] = 1;   
    q.push({0, 0});

    
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        int distance = grid[row][col];

        
        if (row == n - 1 && col == m - 1)
            return distance;

       
        for (const auto& [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;

            
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 0) {
                    
                q.push({newRow, newCol});
                grid[newRow][newCol] = distance + 1;    
            }
        }
    }

    return -1;

    }
};