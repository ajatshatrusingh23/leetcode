class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        vector<int> result;

        if(intervals.empty()) return {};

        result = intervals[0];

        for(int i = 1;i<intervals.size();i++){
            if(result[1] >= intervals[i][0]){
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