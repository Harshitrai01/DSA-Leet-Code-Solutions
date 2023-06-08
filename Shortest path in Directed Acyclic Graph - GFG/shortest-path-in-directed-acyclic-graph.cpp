//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
        //  Creating a adjacency list
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        // Applying topo sort
        vector<int>indeg(N,0);
        for(int i=0;i<N;i++){
            for(auto x:adj[i]){
                indeg[x.first]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        
        vector<int>topoSort;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topoSort.push_back(u);
            for(auto x:adj[u]){
                indeg[x.first]--;
                if(indeg[x.first]==0)
                    q.push(x.first);
            }
        }
        vector<int>dist(N,1e9);
        dist[0]=0;
        for(int i=0;i<N;i++){
            int u=topoSort[i];
            for(auto x:adj[u]){
                int v=x.first;
                int wt_u_to_v=x.second;
                if(dist[v]>dist[u]+wt_u_to_v)
                    dist[v]=dist[u]+wt_u_to_v;
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends