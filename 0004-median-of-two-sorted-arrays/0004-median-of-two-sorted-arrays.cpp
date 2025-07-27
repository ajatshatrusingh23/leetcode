class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> mergedarr(n+m);
        
        for(int i = 0;i<n;i++){
            mergedarr[i] = nums1[i];
        }
        for(int i = 0;i<m;i++){
            mergedarr[i+n] = nums2[i];
        }
        sort(mergedarr.begin(),mergedarr.end());
        double median = 0;

        int nnew = n+m; 
        int i = (nnew-1)/2;

        if(mergedarr.size()%2 == 0){
             
            median = (mergedarr[i] + mergedarr[i+1])/2.0;
        }
        else{
            median = mergedarr[i];
        }
        return median;
    }
};