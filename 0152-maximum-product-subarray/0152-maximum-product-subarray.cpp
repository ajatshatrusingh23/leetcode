class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for(int i = 1;i<n;i++){
            int num =  nums[i];

            int tempMax = max({num,num*maxProd,num*minProd});

            int tempMin = min({num,num*maxProd,num*minProd});

            maxProd = tempMax;

            minProd = tempMin;

            result = max(result,maxProd); 
        }
        return result;

    }
};