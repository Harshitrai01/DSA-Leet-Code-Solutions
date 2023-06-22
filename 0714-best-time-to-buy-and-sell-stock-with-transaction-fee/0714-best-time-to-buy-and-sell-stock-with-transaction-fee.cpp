class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int dp[n+1][2];
        for(int i=n;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                    if(i>=n)
                        dp[i][buy]=0;
                    else{
                        if(buy){
                            int Buy=-prices[i]+dp[i+1][0];
                            int NotBuy=0+dp[i+1][1];
                            dp[i][buy]=max(Buy,NotBuy);
                        }
                        else{
                            int Sell=prices[i]+dp[i+1][1];
                            int NotSell=0+dp[i+1][0];
                            dp[i][buy]=max(Sell-fee,NotSell);
                        }
                    }
            }
        }
        return dp[0][1];   
    }
};