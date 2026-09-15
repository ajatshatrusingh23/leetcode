class Solution {
public:
    void fn(int ind,int target,vector<vector<int>>&arr,vector<int>temp,vector<int>& candidates ,int n){
        if(ind == n){
            if(target != 0){
                return;
            }
        }
        if(target ==0){
            arr.push_back(temp);
            return;
        }
       if (candidates[ind] <= target) {
        temp.push_back(candidates[ind]);

        fn(ind, target - candidates[ind],
           arr, temp, candidates, n);

        temp.pop_back();
    }
        fn(ind+1,target,arr,temp,candidates,n); 

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>arr;
        vector<int>temp;
        int n = candidates.size();

        fn(0,target,arr,temp,candidates,n);

        return arr;
    }
};