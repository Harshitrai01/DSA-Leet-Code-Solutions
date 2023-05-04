//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    int dfs(int u, int v, int k, vector<int>adj[], vector<vector<int>>&dp){
        // vis[u]=1;
        if(k<0) return 0;
        if(u==v and k==0){
            return 1;
        }
        if(dp[u][k]!=-1) return dp[u][k];
        int ans=0;
        for(auto x:adj[u]){
            // if(!vis[x])
                int p=dfs(x,v,k-1,adj,dp);
                ans=(ans+p)%1000000007;
        }
        return dp[u][k]=ans;
    }
  
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    k=k%1000000007;
	    int n=graph.size(),m=graph[0].size();
	    vector<int> adj[n];
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(graph[i][j]==1){
	                adj[i].push_back(j);
	            }
	        }
	    }
	    
	    vector<vector<int>>dp(n,vector<int>(k+1,-1));
	    
	    int ans1=dfs(u,v,k,adj,dp);

	    return ans1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends