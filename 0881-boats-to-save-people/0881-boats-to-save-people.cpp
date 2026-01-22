class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();

        int l = 0;
        int r = n -1;
        int count = 0;

        while(l<=r){
            int sum = people[r] + people[l];

            if(sum <= limit){
                r--;
                l++;
            }
            else if(sum > limit){
                r--;
            }
            else{
                l++;
            }
            count++;

            
        }
        return count;
    }
};