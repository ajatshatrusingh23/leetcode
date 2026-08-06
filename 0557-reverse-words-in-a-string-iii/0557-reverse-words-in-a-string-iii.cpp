class Solution {
public:
    string reverseWords(string s) {
        vector<string>arr;

        string word = "";

        for(int i = 0;i<s.size();i++){
            if(s[i] == ' '){
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    arr.push_back(word);
                    word.clear();
                }
            }
            else{
                word += s[i];
            }
        }

        if(!word.empty()){
            reverse(word.begin(),word.end());
            arr.push_back(word);
        }

        string result = "";

        for(int i = 0;i<arr.size()-1;i++){
            result += arr[i];
            result += " ";
        }

        result += arr[arr.size()-1];

        return result;
    }
};