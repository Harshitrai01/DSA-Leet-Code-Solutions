class Solution {
public:
    
    void solve(vector<vector<int>>& image,int i,int j,int color,int m,int n,int           initial,vector<vector<bool>>&vis){
        
        if(image[i][j]==initial and vis[i][j]==false){
            vis[i][j]=true;
            image[i][j]=color;
            
            // left
            if(j!=0){
                solve(image,i,j-1,color,m,n,initial,vis);
            }
            
            // right
            if(j!=n-1){
                solve(image,i,j+1,color,m,n,initial,vis);
            }
            
            // up
            if(i!=0){
                solve(image,i-1,j,color,m,n,initial,vis);
            }
            
            // down
            if(i!=m-1){
                solve(image,i+1,j,color,m,n,initial,vis);
            }
            return;
            
        }
        else
            return;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int initial=image[sr][sc];
        solve(image,sr,sc,color,m,n,initial,vis);
        return image;
    }
};