//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
	    vector<int> adj[N];
	    for(auto i: prerequisites){
	        adj[i[1]].push_back(i[0]);
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
	    vector<int>ans;
	    
	    while(!q.empty()){
	        count++;
	        int u=q.front();
	        q.pop();
	        ans.push_back(u);
	        for(auto x:adj[u]){
	            inDeg[x]--;
	            if(inDeg[x]==0)
	                q.push(x);
	        }
	    }
	    
	    if(count!=N) ans.clear();
	    return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends