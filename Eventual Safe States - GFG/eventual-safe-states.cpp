//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &recSt, int s, vector<int>&check){
        vis[s]=1;
        recSt[s]=1;
        check[s]=0;
        for(auto u:adj[s]){
            if(!vis[u]){
                if(dfs(adj,vis,recSt,u,check)){
                    check[u]=0;
                    return true; 
                }
                    
            }
            else if(recSt[u]==1){
                check[u]=0;
                return true;                
            }

        }
        check[s]=1;
        recSt[s]=0;
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        vector<int>recSt(V,0);
        
        vector<int>check(V,0);
        vector<int>safeNodes;
        
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(adj,vis,recSt,i,check);
        }
        for(int i=0;i<V;i++){
            if(check[i]==1)
                safeNodes.push_back(i);
        }
        return safeNodes;
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