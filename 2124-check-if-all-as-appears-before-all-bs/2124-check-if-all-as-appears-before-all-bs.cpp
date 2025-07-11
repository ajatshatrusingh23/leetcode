class Solution {
public:
    bool checkString(string s) {
        int n =  s.length();
        int count = 0;
        for(int i = 1;i<n;i++){
            if(s[i-1] != s[i])
                count++;
        }
        if(count>1)
            return false;
        return true;
    }
};