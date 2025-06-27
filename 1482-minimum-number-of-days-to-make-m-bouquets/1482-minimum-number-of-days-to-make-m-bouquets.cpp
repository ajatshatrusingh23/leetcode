class Solution {
public:
int func(vector<int>arr,int day,int m,int k){
    int count = 0;
    int noofbou = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] <= day){
            count++;
        }
        else{
            noofbou += (count/k);
            count = 0;
        }
         
         
    }
    noofbou += (count/k);
     return noofbou>=m;

         
}

    int minDays(vector<int>& bloomDay, int m, int k) {
         int n = bloomDay.size();
         long long total = 1LL * m * k;
          if(total > n) return -1;
        
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(func(bloomDay,mid,m,k)){
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