class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>ans;
        vector<int>dp;

        dp.push_back(1); ans.push_back(dp);
        if(n==1) return ans;
        dp.push_back(1); ans.push_back(dp);
        if(n==2) return ans;
        
        for(int i=2;i<n;i++){
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