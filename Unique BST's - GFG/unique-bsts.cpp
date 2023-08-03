//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int mod=(int)1e9+7;
    int numTrees(int n) 
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
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends