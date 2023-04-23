//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool dfs(string word, vector<vector<char>>&board, vector<vector<int>>&vis, int i, int j, int s){
        
        int n=board.size();
        int m=board[0].size();
        int d_row[8]={-1,1,0,0,-1,1,-1,1};
        int d_col[8]={0,0,-1,1,-1,1,1,-1};
        
        if(i<0 or j<0 or i>=n or j>=m)
            return false;
            
        if(s==word.size() or (word.size()==1 and s==0))
            return true;
        
        if(board[i][j]==word[s] and !vis[i][j]){
            vis[i][j]=1;
            for(int k=0;k<8;k++){
                int n_row=i+d_row[k];
                int n_col=j+d_col[k];
                if(dfs(word,board,vis,n_row,n_col,s+1))
                    return true;
            }
            vis[i][j]=0;
        }
        return false;
    }

    bool check(string word, vector<vector<char>>& board)
    {
            int n=board.size();
            int m=board[0].size();
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]==word[0]){
                        vector<vector<int>>vis(n,vector<int>(m,0));
                        if(dfs(word,board,vis,i,j,0)){
                            return true;
                        }
                    }
                }
            }
            return false;
    }

	vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        set<string>s;
        for(auto x:words){
            if(check(x,board))
                s.insert(x);
        }
        for(auto x:s) ans.push_back(x);
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends