class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>>q;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                    if(mat[i][j] == 0){
                        q.push({i,j});
                        
                    }
                    else{
                        mat[i][j] = -1;
                    }
            }
        }
        vector<int>dx = {0,0,1,-1};
        vector<int>dy = {1,-1,0,0};

        while(!q.empty()){
            vector<int>visited;
            auto node = q.front();
            q.pop();
            int xn  =  node.first;
            int yn = node.second;

            
            
            for(int i = 0;i<4;i++){
                int x = xn + dx[i];
                int y = yn + dy[i];

                if( x >= 0 && y >= 0 && x < m && y < n && mat[x][y] == -1){
                    mat[x][y] = mat[xn][yn] + 1;
                    q.push({x,y});
                }
            }
            
        }

        return mat;
    }
};