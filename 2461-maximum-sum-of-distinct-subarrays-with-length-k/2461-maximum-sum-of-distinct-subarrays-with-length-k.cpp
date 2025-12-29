class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int windowsum = 0;

        for(int i = 0;i<k;i++){
            windowsum += nums[i];
        }

        int maxsum = windowsum;

        for(int i = k;i<n;i++){
            windowsum += nums[i];
            windowsum -= nums[i-k];

            maxsum = max(maxsum,windowsum);
        }

        return maxsum;
    }
};