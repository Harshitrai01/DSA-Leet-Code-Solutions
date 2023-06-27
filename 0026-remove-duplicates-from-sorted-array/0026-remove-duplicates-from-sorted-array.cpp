class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            int i=0;
            int n=nums.size();
            for(int j=i;j<n-1;j++){
                if(nums[j]!=nums[j+1]){
                    nums[i+1]=nums[j+1];
                    i++;
                }
            }

            i++;
            return i;
    }
};