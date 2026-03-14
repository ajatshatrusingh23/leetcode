class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>freq(128,0);

        for(char c: t) freq[c]++;

        int i = 0;
        int count = t.size();
        int min = INT_MAX;
        int a = 0;

        for(int j = 0;j<s.size();j++){
            if(freq[s[j]] > 0)
                count--;

            freq[s[j]]--;

            while(count == 0){
                if(j - i + 1 < min){
                    min = j - i +1;
                    a = i;

                }

                freq[s[i]]++;

                if(freq[s[i]] > 0){
                    count++;
                }

                i++;
            }
        }

        return min == INT_MAX ? "" : s.substr(a, min);
    }
};