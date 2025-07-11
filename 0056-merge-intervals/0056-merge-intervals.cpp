class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<int>result;
        vector<vector<int>> ans;

        result = intervals[0];

        for(int  i = 1;i<intervals.size();i++){
            if(intervals[i][0] <= result[1]){
                result[1] = max(result[1],intervals[i][1]);

            }
            else{
                ans.push_back(result);
                result = intervals[i];
            }

        }
        ans.push_back(result);

        return ans;
    }
};