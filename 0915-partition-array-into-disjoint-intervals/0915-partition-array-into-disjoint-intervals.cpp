class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);    
        vector<int>right(n);
        int leftmax = INT_MIN;
        int rightmin = INT_MAX;
        
        for(int i = 0;i< n;i++){

             leftmax = max(leftmax, nums[i]);
             left[i] = leftmax;
             
        }

        for(int i = n-1;i>=0;i--){
             rightmin = min(rightmin, nums[i]);
             right[i] = rightmin;
        }

        for(int i = 1;i<n;i++){
            if(left[i-1] <= right[i] )
            return i;
        }
        return -1;
    }
};