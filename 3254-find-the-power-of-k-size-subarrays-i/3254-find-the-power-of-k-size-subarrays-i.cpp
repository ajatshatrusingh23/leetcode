class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> result;

        // loop over all subarrays of size k
        for (int i = 0; i <= n - k; i++) {
            bool isValid = true;

            // check if elements are consecutive and sorted
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j + 1] != nums[j] + 1) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(nums[i + k - 1]); // max element
            } else {
                result.push_back(-1);
            }
        }

        return result;
    }
};