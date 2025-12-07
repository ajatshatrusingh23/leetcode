class Solution {
public:
    void helper(int left,int right,vector<char>& s){
        if(left >= right) return;
        swap(s[left],s[right]);
        helper(left+1,right-1,s);
    }

    void reverseString(vector<char>& s) {
        helper(0,s.size()-1,s);
    }
};