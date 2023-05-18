class Solution {
public:
    
    void dfs(int i, int j, int &area, vector<vector<int>>&vis, vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        area++;
        vis[i][j]=1;
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and grid[r][c]==1){
                dfs(r,c,area,vis,grid);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    int area=0;
                    dfs(i,j,area,vis,grid);
                    ans=max(ans,area);
                    cout<<area<<" ";
                }
            }
        }
        
        return ans;
        
    }
};