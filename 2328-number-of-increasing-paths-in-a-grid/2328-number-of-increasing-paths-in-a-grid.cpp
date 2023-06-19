class Solution {
public:
    int mod=1000000007;
    int d_row[4]={0,0,1,-1};
    int d_col[4]={-1,1,0,0};
    
    int solve(vector<vector<int>> &grid,int i, int j, vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        int temp=1;
        for(int k=0;k<4;k++){
            int row=i+d_row[k];
            int col=j+d_col[k];
            if(row>=0 and row<n and col>=0 and col<m and grid[row][col]>grid[i][j]){
                temp=(temp+solve(grid,row,col,dp))%mod;
            }
        }
        return dp[i][j]=temp;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=(ans+solve(grid,i,j,dp))%mod;
            }
        }
        return ans;
    }
};