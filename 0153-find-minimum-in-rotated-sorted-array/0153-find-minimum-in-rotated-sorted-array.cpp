class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int ans = INT_MAX;
        if (nums.size() == 1) return nums[0];
        for(int i = 1;i<nums.size();i++){
            int mini = min(nums[i],nums[i-1]);
            ans = min(ans,mini);
        }

        return ans;
    }
};