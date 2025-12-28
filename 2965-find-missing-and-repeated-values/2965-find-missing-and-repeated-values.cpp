class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>ans;
        vector<int>copy;

     
       
        

        for( int i= 0;i<n ;i++){
            for(int j = 0;j<n;j++){
                copy.push_back(grid[i][j]);
            }
        }

        sort(copy.begin(),copy.end());

     
        int repeating = -1;
        int missing = -1;
        for(int i =1;i<copy.size();i++){
            if(copy[i] == copy[i-1]){
                repeating = copy[i];
            }

            else if(copy[i] != copy[i-1]+1){
                 missing = copy[i]-1;
            }
             
        }
        if(copy[0] != 1){
            missing = 1;
        }

            if (copy.back() != n * n) {
             missing = n * n;
        }


        

        return {repeating,missing};

    }
};