//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and matrix[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<=3;k++){
                int nr=drow[k]+i;
                int nc=dcol[k]+j;
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and matrix[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and matrix[i][j]==1){
                    ans++;
                    q.push({i,j});
                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int k=0;k<=3;k++){
                            int nr=drow[k]+r;
                            int nc=dcol[k]+c;
                            if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and matrix[nr][nc]==1){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
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