//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int d_row[4]={-1,1,0,0};
    int d_col[4]={0,0,-1,1};
    bool dfs(vector<vector<char>>& board, string word, vector<vector<int>>vis, int i, int j, int s){
        int n=board.size();
        int m=board[0].size();
        vis[i][j]=1;
        
        if(s==word.size() or word.size()==1)
            return true;
        for(int k=0;k<4;k++){
                int nr=i+d_row[k];
                int nc=j+d_col[k];
                if(nr<n and nr>=0 and nc<m and nc>=0 and board[nr][nc]==word[s+1] and !vis[nr][nc]){
                    if(s+2==word.size()) return true;
                    if(dfs(board,word,vis,nr,nc,s+1))
                        return true;
                }
        }
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,vis,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends