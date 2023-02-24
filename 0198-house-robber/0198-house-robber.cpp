class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        int dp[n+1];
        dp[0]=0;
        dp[1]=arr[0];
        if(n>1)
            dp[2]=max(arr[0],arr[1]);
        for(int i=3;i<=n;i++){
            int inc=arr[i-1]+dp[i-2];
            int exc=dp[i-1];
            dp[i]=max(inc,exc);
        }
        return dp[n];
    }
};