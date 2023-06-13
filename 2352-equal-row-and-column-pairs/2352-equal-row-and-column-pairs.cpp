class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        multiset<vector<int>>row,col;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
            row.insert(temp);
        }
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            col.insert(temp);
        }
        int ans=0;
        for(auto x:row){
            ans+=col.count(x);
        }
        return ans;
    }
};