class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int idx=-1;
        int mx=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mx){
                idx=i;
                mx=arr[i];
            }
        }
        return idx;
    }
};