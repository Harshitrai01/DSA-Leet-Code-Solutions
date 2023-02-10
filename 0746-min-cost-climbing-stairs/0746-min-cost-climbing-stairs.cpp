class Solution {
public:
    
    int solve(vector<int> cost, int n){
        if(n<=0)
            return 0;
        
        else if(n==1)
            return cost[0];
        
        else{
            int include=cost[n-1]+solve(cost,n-1);
            int exclude=cost[n-1]+solve(cost,n-2);
            return min(include,exclude);            
        }

    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp[n+1];
        for(int i=0;i<=n;i++){
            if(i==0)
                dp[i]=0;
            else if(i==1)
                dp[i]=cost[0];
            else{
                int include=cost[i-1]+dp[i-1];
                int exclude=cost[i-1]+dp[i-2];
                dp[i]=min(include,exclude);            
            }  
        }
        return min(dp[n],dp[n-1]);
    }
};