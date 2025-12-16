class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;

        for(char x: s){
            freq[x]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto it: freq){
            pq.push({it.second,it.first});
        }

        string str ;

         while(!pq.empty()){
            int count = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
                
                while(count--){
                    str.push_back(ch);
                }
         }

        return str;

    }
};