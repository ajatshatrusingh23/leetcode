class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 1;
        long long ans = 0;
        long long count = 0;
        long long m = 1000;
        while(m <= n){
            long long mul = m * 1000;
            long long mini = min(n ,mul-1);
            count  = mini-m + 1;

            ans += count*commas;
            m = mul;
            commas++;
        }

       return ans; 
    }
};