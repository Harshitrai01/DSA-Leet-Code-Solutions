//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    void solve(queue<pair<pair<int,int>,int>>q, vector<vector<int>>& grid, vector<vector<int>> &vis, int &c){
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={0,0,1,-1};
        int dcol[]={-1,1,0,0};
        while(!q.empty()){
            int level=q.front().second;
            int i=q.front().first.first;
            int j=q.front().first.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=i+drow[k];
                int nc=j+dcol[k];
                if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1 and !vis[nr][nc]){
                    vis[nr][nc]=1;
                    grid[nr][nc]=2;
                    q.push({{nr,nc},level+1});
                    c=max(c,level+1);
                }
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},c});
                }
            }
        }
        
        solve(q,grid,vis,c);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   return -1;
                }
            }
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends