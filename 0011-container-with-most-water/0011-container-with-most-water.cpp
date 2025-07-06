class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        long long distance = n-1;
        int left = 0;
        int right = n-1;
        long long area = 0;
        long long maxA = 0;
        long long mini = 0;
        while(left<right){
            mini = min(height[left],height[right]);
            area = mini*distance;

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
            maxA = max(area,maxA);
            distance--;
        }
        return maxA;
    }
};




//2, 4, 6,5,1,3;