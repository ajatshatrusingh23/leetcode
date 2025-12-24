class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum =0 ;
        for(int i = 0;i<apple.size();i++){
            sum += apple[i];
        }

        int count = 0;
        int length = 0;

        sort(capacity.begin(),capacity.end());

        for(int i = capacity.size()-1;i>=0 ; i--){
            length += capacity[i];
            if(length >= sum){
                 
                break;
            }
            count++;
        }
        return count +1;
    }
};