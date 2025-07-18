class Solution {
public:
    void DFS(vector<vector<int>>& image,int i,int j,int r,int c, int& oldcolor,int& newcolor){
        if(i == r || j == c || i<0 || j< 0|| image[i][j] != oldcolor || image[i][j] == newcolor){
            return;
        }
        image[i][j] = newcolor;

        DFS(image,i,j+1,r,c,oldcolor,newcolor);
        DFS(image,i-1,j,r,c,oldcolor,newcolor);
        DFS(image,i,j-1,r,c,oldcolor,newcolor);
        DFS(image,i+1,j,r,c,oldcolor,newcolor);
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c= image[0].size();
        

        int oldcolor = image[sr][sc];
        int newcolor = color;

        

        DFS(image,sr,sc,r,c,oldcolor,newcolor);

        return image;




    }
};