class Solution {
public:
    
    void solve(vector<vector<int>>&ans, vector<int>temp, vector<int>& candidates, int n, int sum, int target){
        
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        
        else if(n==0 or sum>target)
            return;
        
        temp.push_back(candidates[n-1]);
        solve(ans,temp,candidates,n,sum+candidates[n-1],target);
        temp.pop_back();
        solve(ans,temp,candidates,n-1,sum,target);
        return;
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        int n=candidates.size();
        int sum=0;
        
        solve(ans,temp,candidates,n,sum,target);
        
        return ans;
        
    }
};