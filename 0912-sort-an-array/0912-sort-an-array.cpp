class Solution {
public:
   

    void merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;

        int left = low;
        int right = mid + 1;

        // Compare both halves
        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Remaining left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Remaining right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy sorted values back into nums
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }


    void mergesort(vector<int>& nums, int low, int high) {

        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergesort(nums, low, mid);

        mergesort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }


    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums, 0, nums.size() - 1);

        return nums;
    }

};