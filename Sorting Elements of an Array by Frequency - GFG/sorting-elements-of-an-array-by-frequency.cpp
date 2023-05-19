//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool compare(pair<int,int> i1, pair<int,int> i2){
            if(i1.first==i2.first)
                return (i1.second<i2.second);
            return i1.first>i2.first;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<pair<int,int>>help;
        for(auto x:mp){
            help.push_back({x.second,x.first});
        }
        sort(help.begin(),help.end(),compare);
        vector<int>ans;
        for(int i=0;i<help.size();i++){
            int num=help[i].second;
            int freq=help[i].first;
            for(int k=0;k<freq;k++){
                ans.push_back(num);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends