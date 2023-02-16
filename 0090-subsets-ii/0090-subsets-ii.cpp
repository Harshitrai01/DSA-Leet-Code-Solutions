class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int> nums, vector<int>temp, int n){
        if(n==0){
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        
        temp.push_back(nums[n-1]);
        solve(nums,temp,n-1);
        temp.pop_back();
        solve(nums,temp,n-1);
        return;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        solve(nums,temp,n);
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
};