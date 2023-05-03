//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool dfs(vector<int>&vis, vector<int>&pathVis, vector<int>&Check, int i, vector<int> adj[]){
        vis[i]=1;
        pathVis[i]=1;
        Check[i]=0;
        
        for(auto x:adj[i]){
            
            if(!vis[x]){
                if(dfs(vis,pathVis,Check,x,adj))
                    return true;
            }
            
            else if(pathVis[x])
                return true;
        }
        
        pathVis[i]=0;
        Check[i]=1;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        
        vector<int>Check(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(vis,pathVis,Check,i,adj);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(Check[i]==1)
                ans.push_back(i);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends