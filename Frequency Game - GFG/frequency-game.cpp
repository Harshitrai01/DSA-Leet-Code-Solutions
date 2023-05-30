//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        int m=v.size();
        int mn1=v[0].first;
        int mx2=v[0].second;
        
        for(int i=0;i<m;i++){
            if(v[i].first==mn1){
                if(v[i].second>mx2)
                    mx2=v[i].second;
            }
        }
        return mx2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends