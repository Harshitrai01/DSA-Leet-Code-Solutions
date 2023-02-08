//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(vector<int>&dp,int arr[], int n){
	    if(dp[n]!=-1)
	        return dp[n];
	        
	    else{
	        
            if(n==0)
                dp[n]=0;
                
            else if(n==1)
                dp[n]=arr[n-1];
                
            else if(n==2)
                dp[n]=max(arr[n-1],arr[n-2]);
                
            else{
                // Includeing last element and calling for remaining elements
                int include=solve(dp,arr,n-2)+arr[n-1];
                
                // Excludeing last element
                int exclude=solve(dp,arr,n-1);
                
                dp[n]=max(include,exclude);
            }
	    }
	    return dp[n];
	}
	
	int findMaxSum(int *arr, int n) {
	    vector<int>dp(n+1,-1);
	    return solve(dp,arr,n);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends