class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        for(int i = 0;i<nums1.size();i++ ){
            arr.push_back(nums1[i]);
        }
        for(int i = 0;i<nums2.size();i++){
            arr.push_back(nums2[i]);
        }
        sort(arr.begin(),arr.end());

        int n = arr.size();

        if(n%2 != 0){
        int mid = arr.size()/2;
            return arr[mid]/1.0;
        }
        else{

            int mid = n/2;
            return (arr[mid] +arr[mid-1])/2.0;
        }

        


    }
};