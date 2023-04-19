//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>>&vis, int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={0,0,-1,1};
        int dcol[]={1,-1,0,0};
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and grid[i][j]=='X'){
                dfs(grid,vis,r,c);
            }
        }
        
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]=='X'){
                    ans++;
                    dfs(grid,vis,i,j);
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
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends