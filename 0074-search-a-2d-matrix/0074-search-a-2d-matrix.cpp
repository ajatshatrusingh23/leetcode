class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int l = 0;
        int r = n*m -1;

        while(l <= r){
            int midcell = (l + r)/2;

            int ridx = midcell/m;
            int cidx = midcell%m;

            if(matrix[ridx][cidx] == target){
                return true;
            }
            else if(matrix[ridx][cidx] < target){
                l = midcell + 1;
            }
            else{
                r = midcell - 1;

            }
        }

        return false;
    }
};