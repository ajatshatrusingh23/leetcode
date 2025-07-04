class Solution {
public:
void func(vector<int>& nums,int start,vector<int>& temp,vector<vector<int>>&res){
     if(temp.size() == nums.size())
        res.push_back(temp);
       
    
    for(int i = 0;i<nums.size();i++){
      if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;

        temp.push_back(nums[i]);
        func(nums,i+1,temp,res);
        temp.pop_back();
    }
}
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        func(nums,0,temp,ans);
        return ans;
    }
};