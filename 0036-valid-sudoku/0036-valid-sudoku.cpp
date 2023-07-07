class Solution {
public:
    bool isSafe(vector<vector<char>>& grid, int row, int col, char k){
        for(int idx=0;idx<9;idx++){
            if(grid[row][idx]==k or grid[idx][col]==k)
                return false;
            if(grid[3*(row/3)+idx/3][3*(col/3)+idx%3]==k)
                return false;
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    char val=board[i][j];
                    board[i][j]='#';
                    if(!isSafe(board,i,j,val))
                        return false;
                    else
                        board[i][j]=val;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};