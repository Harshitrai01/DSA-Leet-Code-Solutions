//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &nums,int n){
        // 5 -20 -20 -39 -5 0 0 0 36 -32 0 -7 -10 -7 21 20 -12 -34 26 2
            int j=0, ans=0,cnt=0,neg=-1;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    j=i+1;
                    neg=-1;;
                    cnt=0;
                }
                else if(nums[i]<0){
                    cnt++;
                    if(neg==-1)
                        neg=i;
                }
                
                if(cnt%2!=0){
                    ans=max({ans,neg-j,i-neg});
                }
                else
                    ans=max(ans,i-j+1);
                
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends