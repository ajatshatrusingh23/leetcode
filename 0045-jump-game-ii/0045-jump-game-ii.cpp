class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jump = 0;
        int stop = 0;
        int maxmove = 0;

        for(int i = 0;i<n-1;i++){
                maxmove = max(nums[i] +i , maxmove);

                if(i == stop){
                    jump++;
                    stop = maxmove;
                }
            }

        

        return jump;
    }
};