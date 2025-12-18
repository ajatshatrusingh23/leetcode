class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>freq;

        for(char x: s){
            freq[x]++;
        }

        for(char it: t){
             freq[it]--;
             if(freq[it] < 0)
                return  it;
        }

        return {};
    }
};