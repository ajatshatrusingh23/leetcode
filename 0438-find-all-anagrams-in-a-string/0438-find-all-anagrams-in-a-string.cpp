class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = s.length();
        int n = p.length();

        

        vector<int>mp1(26,0);
        vector<int>mp2(26,0);

        vector<int>ans;

        if(n > k) return ans;

        for(int i = 0;i<n;i++){
            mp2[p[i] - 'a']++;
        }

        for(int i = 0;i<n;i++){
            mp1[s[i] - 'a']++;
        }

        if(mp1 == mp2) ans.push_back(0);

        for(int i = n;i<k;i++){
            mp1[s[i] - 'a']++;
            mp1[s[i - n] - 'a']--;

            if(mp1 == mp2) ans.push_back(i-n +1);
        }

        return ans;
    }
};