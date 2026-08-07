class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>arr;
        

        for(int i = 0;i<s.size();i++){
           if(isalnum(s[i])){
                arr.push_back(tolower(s[i]));
           }
            

        }

         

        int left = 0;
        int right = arr.size()-1;

        while(left<right){
            if(arr[left] != arr[right]){
                 return false;
            }
          
             left++;
             right--;
            
        }
        return true;
    }
};