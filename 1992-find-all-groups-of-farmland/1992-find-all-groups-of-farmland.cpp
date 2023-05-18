class Solution {
public:
    
    void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>& land, int &x, int &y, int &ans){
        
        int n=land.size();
        int m=land[0].size();
        
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        vis[i][j]=1;
        
        if(i+j>ans){
            x=i;y=j;
            ans=i+j;
        }
        
        for(int k=0;k<4;k++){
            int r=i+drow[k];
            int c=j+dcol[k];
            if(r>=0 and r<n and c>=0 and c<m and !vis[r][c] and land[r][c]==1){
                dfs(r,c,vis,land,x,y,ans);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        
        vector<vector<int>>ans1;
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and land[i][j]==1){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    int x=i,y=j,ans=i+j;
                    dfs(i,j,vis,land,x,y,ans);
                    temp.push_back(x);
                    temp.push_back(y);
                    ans1.push_back(temp);
                }
            }
        }
        return ans1;
    }
};