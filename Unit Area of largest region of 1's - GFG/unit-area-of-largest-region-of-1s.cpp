//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int i, int j, int &cnt){
        int n=grid.size();
	    int m=grid[0].size();
        cnt+=1;
        vis[i][j]=1;
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
                int r=i+k;
                int c=j+l;
                if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and grid[r][c]==1)
                    dfs(grid,vis,r,c,cnt);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    int ans=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
    	        if(!vis[i][j] and grid[i][j]==1){
    	            int cnt=0;
    	            dfs(grid,vis,i,j,cnt);
    	            ans=max(ans,cnt);
    	        }
	        }
	    }
	    return ans;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends