class Solution {
public:

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0){
                    if(i==0) dp[i][j]=true;
                    else dp[i][j]=false;
                }
                
                else if(i==0){
                    bool flag=true;
                    for(int k=0;k<j;k++){
                        if(p[k]!='*'){
                            flag=false;
                            break;
                        }
                    }
                    dp[i][j]=flag;
                }
                
                else if(s[i-1]==p[j-1] or p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                    
                else{
                    if(p[j-1]=='*')
                        dp[i][j]=dp[i-1][j] or dp[i][j-1];
                    else 
                        dp[i][j]=false;
                } 
            }
        }
        return dp[n][m];
    }

};