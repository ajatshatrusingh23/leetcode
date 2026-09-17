class Solution {
public:
    void fn(int ind,set<vector<int>>&st,vector<int>&temp,vector<int>& nums,int n){
        if(ind == n){
            st.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        fn(ind+1,st,temp,nums,n);

        temp.pop_back();
        fn(ind+1,st,temp,nums,n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>temp;
        int n = nums.size();
        fn(0,st,temp,nums,n);
        vector<vector<int>>arr(st.begin(),st.end());
        return arr;

    }
};