//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
        int maxSum(int n)
        {
            if(n==1 or n==0)
                return n;
            return max(n/2,maxSum(n/2))+max(n/3,maxSum(n/3))+max(n/4,maxSum(n/4)); 
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