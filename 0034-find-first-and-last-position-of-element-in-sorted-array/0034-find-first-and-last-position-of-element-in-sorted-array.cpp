class Solution {
public:
int firstOcc(vector<int> nums,int target){
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while(low<= high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            ans = mid;
            high = mid -1;
        }
        else if(nums[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return ans;
}

int lastOcc(vector<int>nums , int target){
    int low = 0;
    int high = nums.size()-1;
    int ans = -1;
    while(low<= high){
        int mid = (low +high)/2;
        if(nums[mid] == target){
            ans = mid;
            low = mid+1;
        }
        else if(nums[mid] <target) low = mid+1;
        else high = mid -1;
    }
    return ans;
}


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int a = firstOcc(nums,target);
        int b = lastOcc(nums,target);
        res.push_back(a);
        res.push_back(b);
        return res;

    }
};