//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>&vis, int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        int drow[]={0,0,-1,1};
        int dcol[]={-1,1,0,0};
        for(int k=0;k<=3;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and grid[i][j]==1){
                vis[r][c]=1;
                dfs(grid,vis,r,c);
            }
        }
    }

    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and !vis[i][j] and grid[i][j]==1){
                    dfs(grid,vis,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] and grid[i][j]==1){
                    dfs(grid,vis,i,j);
                    ans++;
                }

        return ans;
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends