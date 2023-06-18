class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int dist=0;
        int cap=1;
        while(cap<=mainTank){
            dist+=10;
            if(cap%5==0 and additionalTank>0){
                dist+=10;
                cap++;
                mainTank++;
                additionalTank--;
            }
            cap++;
        }
        return dist;
    }
};