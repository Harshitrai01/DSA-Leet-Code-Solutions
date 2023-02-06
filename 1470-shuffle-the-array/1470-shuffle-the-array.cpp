class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans(2*n);
        int i=0,j=n,k=0;
        while(i<n and j<2*n){
            ans[k]=nums[i];
            ans[k+1]=nums[j];
            i++;j++;k+=2;
        }
        return ans;
    }
};