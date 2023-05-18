class Solution {
public:
    int flag=0;
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        
            if(i<0 or i>=n or j<0 or j>=m)
                return 0;
        
            if(dp[i][j]!=-1)
                return dp[i][j];
        
            int up=0,left=0,down=0;

            if(i-1>=0 and i-1<n and j+1>=0 and j+1<m and grid[i-1][j+1]>grid[i][j])
                up=1+solve(i-1,j+1,grid,dp);

            if(i>=0 and i<n and j+1>=0 and j+1<m and grid[i][j+1]>grid[i][j])
                left=1+solve(i,j+1,grid,dp);

            if(i+1>=0 and i+1<n and j+1>=0 and j+1<m and grid[i+1][j+1]>grid[i][j])
                down=1+solve(i+1,j+1,grid,dp);
        
            return dp[i][j]= max({up,left,down}); 

    }
    
    int maxMoves(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,grid,dp));
        }
        return ans;
    }
};