class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int  n = nums.size();
        int i = 0;
        vector<int>arr;
        while(i<n){
            int correct = nums[i] -1;
            if( nums[i] != nums[correct]){
                swap(nums[i],nums[correct]);
            } 
            else{
                i++;
            }
        } 
        for(int i = 0;i<n;i++){
            if(i +1!= nums[i]){
                arr.push_back(nums[i]);
                arr.push_back(i + 1);
                break;
            }
        }
        return arr;
    }
};