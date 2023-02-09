class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>ans;
        vector<int>dp;
        
        for(int i=0;i<n;i++){
            vector<int>dp1(dp);
            dp1.resize(i+1);
            dp1[0]=1;
            for(int j=1;j<i;j++){
                dp1[j]=dp[j]+dp[j-1];
            }
            dp1[i]=1;
            ans.push_back(dp1);
            dp=dp1;
        }
        return ans;
    }
};