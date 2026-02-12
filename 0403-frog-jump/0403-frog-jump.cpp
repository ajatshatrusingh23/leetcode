class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>>mp;

        unordered_set<int>stonepos(stones.begin(),stones.end());

        mp[0].insert(0);

        int laststone = stones.back();

        for(int pos:stones){
            for(int k : mp[pos]){
                for(int step = k-1;step<= k+1;step++){
                    if(step <= 0) continue;

                    int nextpos = pos + step;

                    if(stonepos.count(nextpos)){
                        mp[nextpos].insert(step);
                    }
                }
            }
        }

        return !mp[laststone].empty();
    }
};