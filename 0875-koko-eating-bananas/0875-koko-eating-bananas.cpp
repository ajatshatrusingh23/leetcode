class Solution {
public:
      bool func(int mid, vector<int>piles,int h){
        long long hours = 0;
        for(int i = 0;i<piles.size();i++){
            hours += ceil((double)piles[i]/mid);
        }
        if(hours<= h){
            return true;
        }
        return false; 

      }  

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());;
        int ans = -1;
        while(low <= high){
            int mid = (low + high) /2;
            if(func(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};