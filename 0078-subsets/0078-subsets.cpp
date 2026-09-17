class Solution {
public:
void fn(int ind,vector<vector<int>>&arr, vector<int>&temp,vector<int>& nums,int n){
   
    if(ind == n){
         arr.push_back(temp);
        return ;
        
    }
    
     
    temp.push_back(nums[ind]);
    fn(ind+1,arr,temp,nums,n);
      
    temp.pop_back();
    fn(ind+1,arr,temp,nums,n);

}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>arr;
        vector<int>temp;
         
        int n = nums.size();
        fn(0,arr,temp,nums,n);

        return arr;
    }
};