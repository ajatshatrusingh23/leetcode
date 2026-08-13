class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int a = n-1;

        for(int i = n-2;i>=0;i--){
            if(i + nums[i] >= a){
                a = i;
            }
        }

        if(a != 0){
            return  false;
        }
        return true;
    }
};