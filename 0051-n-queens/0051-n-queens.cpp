class Solution {
public:

    void addSolution(vector<vector<int>> &board, vector<vector<string>> &ans, int n){
        
        vector<string>temp;
        string s="";
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1)
                    s+="Q";
                else
                    s+=".";
            }
            temp.push_back(s);
            s="";
        }
        
        ans.push_back(temp);
    }
    
    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n,map<int,int>&leftRow,
                map<int,int>&upperDaigonal, map<int,int>&lowerDaigonal){
        
        // base case
        if(col==n){
            addSolution(board,ans,n);
            return;
        }
        
        
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 and lowerDaigonal[row+col]==0 and upperDaigonal[n-1+col-row]==0){
                board[row][col]=1;
                leftRow[row]=1;
                lowerDaigonal[row+col]=1;
                upperDaigonal[n-1+col-row]=1;
                solve(col+1,ans,board,n,leftRow,upperDaigonal,lowerDaigonal);
                board[row][col]=0;
                leftRow[row]=0;
                lowerDaigonal[row+col]=0;
                upperDaigonal[n-1+col-row]=0;
            }
        }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<int>> board(n,vector<int>(n,0));
        map<int,int>leftRow,upperDaigonal,lowerDaigonal;
        vector<vector<string>> ans;
        
        solve(0,ans,board,n,leftRow,upperDaigonal,lowerDaigonal);
        return ans;
        
    }
};