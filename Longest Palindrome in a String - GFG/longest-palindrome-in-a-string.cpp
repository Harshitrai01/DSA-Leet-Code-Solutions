//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        string s1=S;
        reverse(S.begin(),S.end());
        string s2=S;
        
        int n=s1.size();
        int dp[n+1][n+1];
        int ans=0;
        int x=0,y=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if( dp[i][j]>ans and abs(dp[i][j]-i)==abs(n-j) ){
                        ans=dp[i][j];
                        x=i;y=j;
                    }
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        // cout<<x<<" "<<y<<endl;
        // cout<<ans<<endl;
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        string res="";
        while(dp[x][y]!=0){
            res+=s1[x-1];
            x--;y--;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends