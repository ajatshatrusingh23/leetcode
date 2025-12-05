class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;

        string dou = s+s;

        return (dou.find(goal) != string::npos);
    }
};