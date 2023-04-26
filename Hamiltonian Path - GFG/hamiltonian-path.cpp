//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    bool dfs(int i, vector<int>&vis, vector<int> adj[], int c, int n){
        if(n==c)
            return true;
        vis[i]=1;
        for(auto s:adj[i]){
            if(!vis[s]){
                if(dfs(s,vis,adj,c+1,n))
                    return true;
            }
        }
        vis[i]=0;
        return false;
    }
    
    bool check(int n,int m,vector<vector<int>> Edges)
    {
        vector<int> adj[n+1];
        
        for(int i=0;i<m;i++){
            adj[Edges[i][0]].push_back(Edges[i][1]);
            adj[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        vector<int>vis(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(dfs(i,vis,adj,1,n))
                return true;
        }
        
        return false;
        
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends