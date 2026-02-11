class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<int> te = nums;

        vector<long long> merge;

        for(long long x: te){
            while(!merge.empty() && merge.back() == x){
                x = x+ merge.back();
                merge.pop_back();
            }
            merge.push_back(x);
        }
        return merge;
    }
};