class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,1);

        for(int i = 1;i<n;i++){
            if(nums[i-1] < nums[i]){
                dp[i] = max(dp[i],dp[i-1] + 1);
            }
            else{
                dp[i] = 1;
            }

        }

        return *max_element(dp.begin(),dp.end());
    }
};