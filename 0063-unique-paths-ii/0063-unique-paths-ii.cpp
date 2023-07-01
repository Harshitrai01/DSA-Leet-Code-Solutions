class Solution {
public:

    // int solve(vector<vector<int>>& obstacleGrid, int i, int j){
    //     if(i==0 or j==0)
    //         return 0;
    //     else if(obstacleGrid[i-1][j-1]==1)
    //         return 0;
    //     else if(i==1 and j==1)
    //         return 1;
    //     int left=solve(obstacleGrid,i,j-1);
    //     int up=solve(obstacleGrid,i-1,j);
    //     return left+up;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // return solve(obstacleGrid,m,n);
        int mod=1000000007;
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(obstacleGrid[i-1][j-1]==1)
                    dp[i][j]=0;
                else if(i==1 and j==1)
                    dp[i][j]=1;
                else{
                    int left=dp[i][j-1];
                    int up=dp[i-1][j];
                    dp[i][j]=(left+up);                   
                }
            }
        }
        return dp[m][n];
    }
};