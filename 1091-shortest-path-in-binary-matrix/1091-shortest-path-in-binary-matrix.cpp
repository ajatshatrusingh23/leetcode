class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
                return -1;
        }

        queue<pair<int,pair<int,int>>>q;

        q.push({1,{0,0}});
         

        vector<vector<int>>dist(n,vector<int>(m,1e9));
            dist[0][0] = 1;
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;

            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1) {
            return dis;
            }

            for(int i = 0;i<8;i++){
                int row = r + dr[i];
                int col = c + dc[i];
            if(row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 0 && dis +1 < dist[row][col] ){

                dist[row][col] = 1 + dis;
                    if(row == n-1 && col == m-1){
                         return dis + 1;
                     }
                q.push({1+dis,{row,col}});
            }
        
        }
    }
        
    return -1;

    }
};