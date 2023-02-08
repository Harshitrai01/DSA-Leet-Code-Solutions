//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
        int solve(int n){
            
            int a=n/2,b=n/3,c=n/4;
            if(n==1)
                return 1;
            
            else if(n==0)
                return 0;
            
            else
            return max(a,solve(n/2))+max(b,solve(n/3))+max(c,solve(n/4));  
        }
    
        int maxSum(int n)
        {
            return solve(n);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends