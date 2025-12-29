class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         unordered_set<int> st;
    long long currSum = 0, maxSum = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {

        // Remove duplicates
        while (st.count(nums[right])) {
            st.erase(nums[left]);
            currSum -= nums[left];
            left++;
        }

        // Add current element
        st.insert(nums[right]);
        currSum += nums[right];

        // Check window size
        if (right - left + 1 == k) {
            maxSum = max(maxSum, currSum);

            // Slide window
            st.erase(nums[left]);
            currSum -= nums[left];
            left++;
        }
    }

    return maxSum;
    }
};