//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int d_row[8]={-1,1,0,0,-1,1,-1,1};
    int d_col[8]={0,0,-1,1,-1,1,1,-1};
    
    bool solve(vector<vector<char>>& board,string word,vector<vector<int>>&vis,int m, int n, int s,
    int i, int j){
        
        
        if(i<0 or j<0 or i>=m or j>=n)
            return false;
            
        if(s==word.size() or word.size()==1)
            return true;
        
        if(board[i][j]==word[s] and !vis[i][j]){
            vis[i][j]=1;
            for(int k=0;k<8;k++){
                int n_row=i+d_row[k];
                int n_col=j+d_col[k];
                if(solve(board,word,vis,m,n,s+1,n_row,n_col))
                    return true;
            }
            vis[i][j]=0;
        }
            
        return false;
    }
    
        bool check_this(string s,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(s[0]==board[i][j]){
                    vector<vector<int>>visited(board.size(), vector<int> (board[0].size(),0));
                    if(solve(board,s,visited,m,n,0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    int m=board.size();
	    int n=board[0].size();
	    vector<string>ans;
        for(int i=0;i<dictionary.size();i++){
            if(check_this(dictionary[i],board)){
	            ans.push_back(dictionary[i]);
	        }
        }
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