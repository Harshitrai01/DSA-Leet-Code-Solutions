//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	typedef pair<int,int> Pair;
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // We can use set also to erase the distances which are going to take
        // extra iterations for no use. (10,5) and (8,5). We will remove (10,5).
        
        // This doest not improve much time complexity but it improves or minimizes
        // the extra iterations.
        
        set<Pair>s;
        s.insert({0,S});
        vector<int>dist(V,1e9);
        dist[S]=0;
        
        while(!s.empty()){
            auto it=*(s.begin());
            int u=it.second;
            s.erase(it);
            for(auto it1:adj[u]){
                // Getting adjacent node and wt (u to v).
                int v=it1[0];
                int wt=it1[1];
                
                if(dist[v]>dist[u]+wt){
                    
                    // If the exists previously and we founded the better one,
                    // remove the preveious one whcih will dave iterations.
                    if(dist[v]!=1e9)
                        s.erase({dist[v],v});
                    
                    dist[v]=dist[u]+wt;
                    s.insert({dist[v],v});
                }
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends