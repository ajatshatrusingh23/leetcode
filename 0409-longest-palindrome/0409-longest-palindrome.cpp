class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;

        for(char c: s){
            freq[c]++;
        }

        int sum = 0;
        bool odd = false;

        for(auto it: freq){
            if(it.second %2 == 0){
                sum += it.second;
            }
            else if(it.second % 2 != 0){
                sum += (it.second-1);
                odd = true;


            }
        }

        if(odd)sum += 1;

        return sum;
        

    }
};