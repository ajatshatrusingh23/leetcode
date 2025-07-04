class Solution {
public:
    bool Ispalindrome(string s,int low,int high){
        while(low<high){
            if(s[low] != s[high])
                return false;
                low++;
                high--;
            
        }
        return true;
    }

    void func(vector<vector<string>>& res , vector<string>& temp,string s,int start){
        if(start == s.size()){
            res.push_back(temp);
            return;
        }
        for(int i = start;i<s.size();i++){
            if(!Ispalindrome(s,start,i)) continue;
            temp.push_back(s.substr(start, i - start + 1));
            func(res,temp,s,i+1);
            temp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        func(res,temp,s,0);
        return res;
    }
};