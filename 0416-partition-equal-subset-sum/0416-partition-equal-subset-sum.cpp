class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
        }

        if(sum%2 != 0) return false;

        long long n = nums.size();
        long long m = sum/2;

        vector<vector<unsigned long>>dp(n+1,vector<unsigned long>(m+1,0));

        dp[0][0] = 1;

        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(nums[i-1] >j){
                    dp[i][j] = dp[i-1][j];
                }

                else{
                    dp[i][j] = dp[i-1][j] +dp[i-1][j-nums[i-1]];
                }
            }
        }

        return dp[n][m] != 0;
    }
};