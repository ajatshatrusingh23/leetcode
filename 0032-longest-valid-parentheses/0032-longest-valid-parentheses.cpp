class Solution {
public:
    int longestValidParentheses(string s) {
        int left  = 0;
        int right = 0;
        int maxlen = 0;

        for(int i = 0;i<s.size();i++){
            if(s[i] == '(') left++;
            else right++;

            if(right == left){
                maxlen = max(maxlen,2*right);

            }
            else if(right>left){
                right = left = 0;
            }
        }
         left = right = 0;

        for(int i = s.size()-1 ;i>=0;i--){
            if(s[i] == '(' ) left++;
            else right++;

            if(right == left){
                maxlen = max(maxlen,2*left);
            }
            else if(left>right){
                right = left = 0;
            }
         }

         return maxlen;
    }
};