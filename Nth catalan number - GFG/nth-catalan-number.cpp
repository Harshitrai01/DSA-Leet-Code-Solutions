//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int mod=1e9+7;
    int findCatalan(int n) 
    {
        int dp[n][n+1];
        for(int j=0;j<n+1;j++){
            for(int i=0;i<n;i++){
                if(j==0){
                    dp[i][j]=1;
                }
                else if(i==j-1){
                    dp[i][j]=dp[i][j-1]%mod;
                }
                else{
                    dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j]%mod)%mod;
                }
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Counsigned long int