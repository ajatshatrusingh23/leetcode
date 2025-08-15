class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int maxcu = nums[0];
       int mincu = nums[0];
        int maxov = nums[0];

       for(int i =1;i<nums.size();i++){
            int curr = nums[i];
            int temp = maxcu;
            maxcu = max({ curr, curr*maxcu,curr*mincu});
            mincu = min({curr,curr*temp,curr*mincu});

            maxov = max(maxov,maxcu);
       } 
       return maxov;
    }
};