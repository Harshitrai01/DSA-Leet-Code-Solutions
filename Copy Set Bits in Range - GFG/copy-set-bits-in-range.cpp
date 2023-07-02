//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        
        int ans=x;
        x=x>>(l-1);
        y=y>>(l-1);
        
        int count=l;
        while(count<=r){
            if(!(x&1) and (y&1)){
                ans+=pow(2,count-1);
            }
            y=y>>1;
            x=x>>1;
            count++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}
// } Driver Code Ends