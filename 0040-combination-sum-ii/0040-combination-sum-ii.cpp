class Solution {
public:
    void fn(int ind , vector<vector<int>>&arr ,vector<int>&temp,
     vector<int>& candidates ,int  target, int n ,int sum){
         
        if(target== 0){
            arr.push_back(temp);
            return;
        }

        for(int i = ind;i<n;i++){
            if(i > ind && candidates[i] == candidates[i - 1])
            continue;

           if(candidates[i]>target){
            break;
           }

        temp.push_back(candidates[i]);
        fn(i+1,arr,temp,candidates,target-candidates[i],n,sum);
        temp.pop_back();
        }
        
     }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>arr;
        vector<int>temp;
        int n = candidates.size();
        int sum = 0;
        fn(0,arr,temp,candidates,target,n,sum);

        

        return arr;
    }
};