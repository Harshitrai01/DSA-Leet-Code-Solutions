class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=nums[0]+k, h=nums[nums.size()-1]-k;
        if(h-l<=0)
            return 0;
        return h-l;
    }
};