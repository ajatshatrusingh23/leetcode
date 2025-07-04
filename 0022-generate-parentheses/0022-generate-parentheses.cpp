class Solution {
public:
    void parenthesis(vector<string>& res,string ans,int open,int close,int n){
        if(close == n){
            res.push_back(ans);
        }
        if(open <n){
            parenthesis(res,ans+'(',open+1,close,n);

        }
        if(open>close){
            parenthesis(res,ans+')',open,close+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string anl = "";
        parenthesis(ans,anl,0,0,n);
        return ans;

    }
};