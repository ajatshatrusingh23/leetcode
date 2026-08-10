class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";

        int n = word1.size();
        int m = word2.size();

        int i = 0;
        int j = 0;

        while(i<n || j < m){
            if(i<n){
                s += word1[i];
                  i++;
            }
            if(j<m){
            s += word2[j];
            j++;
            }
            
             
        }
    return s;
        
    }
};