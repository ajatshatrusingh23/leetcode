class Solution {
public:
    string helper(string s){
        string st = "";

        for(char c : s){
            if (c != '#'){
                st.push_back(c);
            }

            else{
                if(!st.empty()){
                    st.pop_back();
                }
            }
        }

        return st;
    }

    bool backspaceCompare(string s, string t) {
        return helper(s) == helper(t);
        

    }
};