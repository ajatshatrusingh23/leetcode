class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roadmap = {
            {'I', 1}, {'V', 5}, {'X', 10},{'L',50}, {'C', 100}, {'D', 500}, {'M' , 1000}
        };
        int res =0;
        int n = s.length();
        for(int i =0;i<n;i++){
            if(i+1 <n && roadmap[s[i]]<roadmap[s[i+1]]){
                res -= roadmap[s[i]];
            }
            else
                res += roadmap[s[i]];
        }

        return res;
    }
};