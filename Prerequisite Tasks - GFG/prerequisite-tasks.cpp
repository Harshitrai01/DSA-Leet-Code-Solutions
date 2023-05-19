//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> adj[N];
	    for(auto i: prerequisites){
	        adj[i.second].push_back(i.first);
	    }
	    
	    vector<int>inDeg(N,0);
	    
	    for(int i=0;i<N;i++){
	        for(auto j :adj[i]){
	            inDeg[j]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(inDeg[i]==0) q.push(i);
	    }
	    
	    int count=0;
	    while(!q.empty()){
	        count++;
	        int u=q.front();
	        q.pop();
	        for(auto x:adj[u]){
	            inDeg[x]--;
	            if(inDeg[x]==0)
	                q.push(x);
	        }
	    }
	    
	    if(count==N) return true;
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends