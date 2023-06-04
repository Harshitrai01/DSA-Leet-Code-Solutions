class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        vector<int>row(n,0);
        vector<int>col(n,0);
        long long ans=0;
        int r=n,c=n;
        for(int i=queries.size()-1;i>=0;i--){
            
            int type=queries[i][0];
            int index=queries[i][1];
            int val=queries[i][2];
            
            if(type==0 and row[index]==0){
                row[index]=1;
                r--;
                ans+=(c*val);
            }
            if(type==1 and col[index]==0){
                col[index]=1;
                c--;
                ans+=(r*val);
            }
            
        }
        return ans;
    }
};