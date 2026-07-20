class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& image , int n , int m , int original, int color){

        if(i < 0 || j< 0 || i>= n || j>= m )
            return;

        if(image[i][j] != original)
            return;
        
        image[i][j] = color;

        dfs(i+1 , j , image ,n,m ,original, color );
          dfs(i-1 , j , image ,n , m,original , color );
           dfs(i , j+1 , image ,n, m, original, color );
            dfs(i , j-1 , image ,n,m, original, color );
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];

        if(original == color)
            return image;

        dfs(sr,sc,image,n,m,original,color);       
 

        return image;

    }
};