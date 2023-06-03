class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int area=0;
        int i=0,j=n-1;
        while(i<j){
            int curr_area=0;
            int l=j-i;
            curr_area=l*min(height[i],height[j]);
            area=max(area,curr_area);
            if(height[i]<height[j]){
                i++;
            }
            else if(height[j]<height[i]){
                j--;
            }
            else{
                i++;j--;
            }
        }
        return area;
    }
};