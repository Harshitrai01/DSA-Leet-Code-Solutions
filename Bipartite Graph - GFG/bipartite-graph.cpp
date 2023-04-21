//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(vector<int>graph[], vector<int>&color, int i){
        color[i]=0;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto node:graph[u]){
                if(color[node]==-1){
                    color[node]=!color[u];
                    q.push(node);
                }
                else if(color[node]==color[u])
                    return false;
            }
        }
        return true;
    }


	bool isBipartite(int v, vector<int>adj[]){
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(!check(adj,color,i))
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