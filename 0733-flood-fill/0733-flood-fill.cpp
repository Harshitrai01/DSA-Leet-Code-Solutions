class Solution {
public:
    
    void solve(vector<vector<int>>& image,int i,int j,int color,int m,int n,int           initial){
        if(i<0 or j<0 or i>=m or j>=n or image[i][j]==color)
            return;
        if(image[i][j]==initial){
            image[i][j]=color;
            
            int d_row[4]={-1,0,1,0};
            int d_col[4]={0,1,0,-1};
            
            for(int k=0;k<4;k++){
                int n_row=i+d_row[k];
                int n_col=j+d_col[k];
                solve(image,n_row,n_col,color,m,n,initial);
            }
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int initial=image[sr][sc];
        solve(image,sr,sc,color,m,n,initial);
        return image;
    }
};