//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>&board, vector<vector<int>>&vis, int i, int j){
        int n=board.size();
        int m=board[0].size();
        vis[i][j]=1;
        int drow[]={0,0,1,-1};
        int dcol[]={-1,1,0,0};
        for(int k=0;k<=3;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and board[r][c]=='O'){
                vis[r][c]=1;
                dfs(board,vis,r,c);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 or i==n-1 or j==0 or j==m-1) and board[i][j]=='O' and !vis[i][j]){
                    vis[i][j]=1;
                    dfs(board,vis,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends