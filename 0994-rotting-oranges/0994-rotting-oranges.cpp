class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        int rotten = 0;

        queue<pair<int,int>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    rotten++;
                    q.push({i,j});
                }
            }
        }

        if(fresh == 0) return 0;

        int min = 0;

        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        while(!q.empty()){
            int size = q.size();
            bool turn = false;

            for(int i = 0;i<size;i++){
                 auto node = q.front();

                 q.pop();

                for(int i = 0;i<4;i++){
                    int x = node.first + dx[i];
                    int y = node.second + dy[i];

                    if(x >= 0 && y >= 0 && x < n && y<m && grid[x][y] == 1 ){
                        q.push({x,y});
                        grid[x][y] = 2;
                        fresh--;
                        turn  = true;
                    }
                }
            }
            if(turn) min++;
         }

         return (fresh == 0)?min:-1;

    }
};