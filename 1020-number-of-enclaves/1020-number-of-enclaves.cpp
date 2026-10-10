class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if((i== 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1 ){
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(int i = 0;i<4;i++){
                int x = node.first + dx[i];
                int y = node.second + dy[i];

                if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1){
                    grid[x][y] = 0;
                    q.push({x,y});
                }
            }
        }


 
 int count = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                
                    if(grid[i][j] == 1)
                        count++;

                
            }
        }
 
        return count;
    }
};