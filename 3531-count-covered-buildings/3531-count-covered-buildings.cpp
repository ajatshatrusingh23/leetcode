class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int m = buildings.size();
        if(m == 0) return 0;

        unordered_map<int,int>minY,maxY;
        unordered_map<int,int>minX,maxX;

        for(auto &b: buildings){
            int x = b[0] , y = b[1];

            if(minY.find(x) == minY.end()){
                minY[x] = y;
                maxY[x] = y;
            }
            else{
                minY[x] = min(minY[x],y);
                maxY[x] = max(maxY[x],y);
            }

            if(minX.find(y) == minX.end()){
                minX[y] = x;
                maxX[y] = x;
            }
            else{
                minX[y] = min(minX[y],x);
                maxX[y] = max(maxX[y],x);


            }
        } 

        int count = 0;

        for(auto &b: buildings){
            int x = b[0] , y = b[1];

            bool hasLeftRight = (minY[x] < y && y < maxY[x]);

            bool hasUpDown = (minX[y] < x && x < maxX[y]);

            if(hasLeftRight && hasUpDown)
                count++;
        }

        return count;
    }
};