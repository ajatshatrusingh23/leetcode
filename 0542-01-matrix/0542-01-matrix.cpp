class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
                else {
                    mat[i][j] = -1;
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

                if( x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == -1){
                    mat[x][y] = mat[node.first][node.second]+ 1;
                    q.push({x,y});
                }
             }

            
        }

        return mat;
        
    }
};