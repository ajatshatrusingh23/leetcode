class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
                
            }
        }
        return true;
    }

    void fun(int ind, string s,vector<vector<string>> &res,vector<string>&temp ){
        if(ind == s.length()){
            res.push_back(temp);
            return;
        }

        for(int i = ind;i<s.length();i++){
            if(isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                fun(i+1,s,res,temp);
                temp.pop_back();
            }        
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string>temp;

        fun(0,s,res,temp);
        return res;
    }
};