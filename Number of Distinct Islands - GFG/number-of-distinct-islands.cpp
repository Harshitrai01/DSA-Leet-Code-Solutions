//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis,
    vector<pair<int,int>>&temp, int i, int j, int io, int jo){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        temp.push_back({i-io,j-jo});
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        for(int k=0;k<=3;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1 and !vis[r][c]){
                dfs(grid,vis,temp,r,c,io,jo);
            }
        }
        
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set< vector< pair<int,int> > >s;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>>temp;
                    dfs(grid,vis,temp,i,j,i,j);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends