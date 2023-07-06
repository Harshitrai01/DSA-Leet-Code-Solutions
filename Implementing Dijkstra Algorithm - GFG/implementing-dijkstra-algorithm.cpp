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
        // We will use min heap priority queue to store the distances and edges.
        // We will use pairs to store {distance,node} in min heap pq.
        
        // Creating a min heap priority queue.
        priority_queue<Pair, vector<Pair>, greater<Pair>>pq;
        pq.push({0,S});
        vector<int>dist(V,1e9);
        dist[S]=0;
        
        while(!pq.empty()){
            // Extracting the node and distance upto that node.
            int dis=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            for(auto it:adj[u]){
                // Getting adjacent node and wt (u to v).
                int v=it[0];
                int wt=it[1];
                if(dist[v]>dis+wt){
                    dist[v]=dis+wt;
                    pq.push({dist[v],v});
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