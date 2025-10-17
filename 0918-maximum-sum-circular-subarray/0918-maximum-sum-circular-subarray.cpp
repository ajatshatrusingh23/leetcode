class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int  total_sum = 0;
        int maxSum = INT_MIN , curMax = 0;
        int minSum = INT_MAX , curMin = 0;

        for(int x: nums) {
            total_sum += x;

            curMax = max(x,curMax +x);

            maxSum = max(maxSum,curMax);

            curMin = min(x, curMin +x);
            minSum = min(minSum, curMin);

        }

        if(maxSum <0) return maxSum;

        return max(maxSum , total_sum-minSum);
    }
};