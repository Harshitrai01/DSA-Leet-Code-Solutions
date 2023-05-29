class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                set<int>s1;
                int r1=i-1,c1=j-1;
                while(r1>=0 and c1>=0){
                    s1.insert(grid[r1][c1]);
                    r1--;c1--;
                }
                set<int>s2;
                int r2=i+1,c2=j+1;
                while(r2<n and c2<m){
                    s2.insert(grid[r2][c2]);
                    r2++;c2++;
                }
                int s=abs((int)s1.size()-(int)s2.size());
                ans[i][j]=s;
            }
        }
        return ans;
    }
};