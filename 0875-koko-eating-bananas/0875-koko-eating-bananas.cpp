class Solution {
public:
    bool func(int mid,vector<int>& piles,int h){
        long long hour = 0;

        for(int i = 0;i<piles.size();i++){
            hour += ceil((double)piles[i]/mid);
        }

        return hour<=h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = -1;
        int high = 1e9;

        int low = 1;
        while(low<=high){
            int mid = (low+high)/2;

            if(func(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }

            else {
                low = mid+1 ; 
            }
        }

        return ans;
    }
};