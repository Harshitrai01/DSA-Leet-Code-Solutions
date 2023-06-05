class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size=coordinates.size();
        int x1=coordinates[0][0],y1=coordinates[0][1];
        int x2=coordinates[size-1][0],y2=coordinates[size-1][1];
        int dx=x2-x1;
        int dy=y2-y1;
        for (int i=0;i<size;i++){
            int ddx=coordinates[i][0] - coordinates[0][0];
            int ddy=coordinates[i][1] - coordinates[0][1];
            if(ddx*dy!=ddy*dx) return false;
        }
        return true;
    }
};