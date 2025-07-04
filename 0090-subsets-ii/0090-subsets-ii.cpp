class Solution {
public:
    void func(vector<int> &nums,int start,vector<int> &temp,vector<vector<int>> &res){
        sort(nums.begin(),nums.end());
        res.push_back(temp);
        
        for(int i = start;i<nums.size();i++){
            if(i>start && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            func(nums,i+1,temp,res);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        func(nums,0,temp,ans);
     
        return ans;
    }
};