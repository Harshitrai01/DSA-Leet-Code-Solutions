//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>&vis, int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                    ans++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends