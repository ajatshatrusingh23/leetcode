class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
         

        int n = s.length();
        int m = t.length();

        int count = 0;
         int j = 0;
        while(i < n && j<m  ){
              
                if(s[i] == t[j]){
                    count++;
                    i++;
                }
             j++;
        }

      

        return count == n;

    }
};