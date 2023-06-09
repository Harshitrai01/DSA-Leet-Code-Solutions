//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int>TopoSort(vector<int>adj[], int n, vector<int>&dist){
            vector<int>topoSort;
            vector<int>indegree(n,0);
            for(int i=0;i<n;i++){
                for(auto x:adj[i])
                    indegree[x]++;
            }
            queue<int>q;
            for(int i=0;i<n;i++){
                if(indegree[i]==0){
                    q.push(i);
                    dist[i]=1;
                }
            }
            while(!q.empty()){
                int u=q.front();
                q.pop();
                topoSort.push_back(u);
                for(auto x:adj[u]){
                    indegree[x]--;
                    if(indegree[x]==0){
                        q.push(x);
                    }
                }
            }
            return topoSort;
        }
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int>adj[n];
            for(int i=0;i<m;i++){
                adj[edges[i][0]-1].push_back(edges[i][1]-1);
            }
            
            vector<int>dist(n,1e9);
            vector<int>topoSort=TopoSort(adj,n,dist);
            for(int i=0;i<n;i++){
                int u=topoSort[i];
                for(auto v:adj[u]){
                    // if(dist[v]>dist[u]+1){
                        dist[v]=dist[u]+1;
                    // }
                }
            }
            return dist;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends