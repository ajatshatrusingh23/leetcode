class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int>mp;
        vector<int>ans;

        for(int i = 1;i<cbrt(n);i++){
            int a = i*i*i;
            for(int j = i;j<cbrt(n);j++){
                int b = j*j*j;
                int sum = a+b;
                if(sum <= n){
                    mp[sum]++;

                }
                else{
                    break;
                }

            }
            
        }
        for(auto it:mp){
            if(it.second >= 2 ){
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(),ans.end());

        return ans;

    }
};