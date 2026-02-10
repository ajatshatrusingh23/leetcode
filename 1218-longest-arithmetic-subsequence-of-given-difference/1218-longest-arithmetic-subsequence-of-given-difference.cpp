class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
         unordered_map<int, int> dp;
    int ans = 0;

    for (int num : arr) {
        int prev = num - difference;
        dp[num] = dp.count(prev) ? dp[prev] + 1 : 1;
        ans = max(ans, dp[num]);
    }

    return ans;
    }
};