class Solution {
public:
void fn(int ind, vector<vector<int>>&arr,vector<int>& nums,int n){
    if(ind == n){
        arr.push_back(nums);
        return;
    }

    for(int i = ind;i<n;i++){
        swap(nums[ind],nums[i]);
        fn(ind +1,arr,nums,n);
        swap(nums[ind],nums[i]);

    }
}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>arr;
        int n = nums.size();
        fn(0,arr,nums,n);

        return arr;
    }
};