class Solution {
public:
    void dfs(int i, int j ,vector<vector<int>>& image , int n ,int m, int color , int oldcolor){
        if(i<0 || j<0 || i == n || j ==  m || image[i][j] != oldcolor || image[i][j] == color )
            return ;

        image[i][j] = color;

        dfs(i+1,j,image,n,m,color , oldcolor);
        dfs(i-1,j,image,n,m,color , oldcolor);
        dfs(i,j+1,image,n,m,color , oldcolor);
        dfs(i,j-1,image,n,m,color , oldcolor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int oldcolor = image[sr][sc];
        
         
             
        dfs(sr,sc,image, n, m,color, oldcolor);


        return image;
    }
};