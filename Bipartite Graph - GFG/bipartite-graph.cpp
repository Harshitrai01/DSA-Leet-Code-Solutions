//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(vector<int>&color, vector<int>adj[], int i){
        for(auto x:adj[i]){
            if(color[x]==-1){
                color[x]=!color[i];
                if(!dfs(color,adj,x))
                    return false;
            }
            if(color[x]==color[i])
                return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
        vector<int>color(V,-1);
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                color[i]=1;
                if(!dfs(color,adj,i))
                    return false;
            }
        }
        return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends