class Solution {
public:
    void func(int ind ,vector<int>& nums , vector<vector<int>>&ans , int n  ){
        if (ind == n){
            ans.push_back(nums);
            return;
        }

        for(int i = ind ;i<n;i++){
            swap(nums[ind],nums[i]);
            func(ind +1,nums,ans,n);
            swap(nums[ind],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        func(0,nums,ans,n);

        return ans;

    }
};