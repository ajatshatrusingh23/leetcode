class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

    int l = 0;
    int pr = 1;
    int ans = 0;

    for (int i = 0; i < nums.size(); i++) {
        pr *= nums[i];

        while (pr >= k) {
            pr /= nums[l];
            l++;
        }

        ans += (i - l + 1);
    }

    return ans;
}

  
};