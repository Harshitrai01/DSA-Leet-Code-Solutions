//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    bool isPal(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }

    bool makePalindrome(int n,vector<string> &arr){
        unordered_map<string,int>mp;
        for(auto x:arr){
            mp[x]++;
            string s=x;
            reverse(s.begin(),s.end());
            mp[s]--;
        }
        
        for(auto x:mp){
            if(x.second!=0)
                return isPal(x.first);
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends