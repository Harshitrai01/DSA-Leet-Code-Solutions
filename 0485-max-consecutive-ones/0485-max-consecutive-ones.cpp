class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0,ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                res++;
                ans=max(ans,res);
            }
            else{
                res=0;
            }
        } return ans;
    }
};