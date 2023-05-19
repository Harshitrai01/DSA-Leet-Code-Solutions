class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<pair<int,int>>help;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    help.push_back({i,j});
                }
            }
        }
        
        for(auto x:help){
            int r=x.first;
            int c=x.second;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(r==i or c==j)
                        matrix[i][j]=0;
                }
            }
        }
        
    }
};