class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,444));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 and j!=0)
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                if(j==0 and i!=0)
                    dp[i][j]=dp[i-1][j]+grid[i][j];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]),INT_MAX);
            }
        }
        return dp[m-1][n-1];
    }
};