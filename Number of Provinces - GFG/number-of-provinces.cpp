//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void dfs(vector<int> list[], vector<bool>&vis, int i){
        vis[i]=true;
            for(auto x:list[i]){
                if(vis[x]==false){
                    dfs(list,vis,x);
                }
            }
    }
  
    int numProvinces(vector<vector<int>> adj, int V){
        vector<int> list[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j and adj[i][j]==1){
                    list[i].push_back(j);
                    list[j].push_back(i);                    
                }
            }
        }
        int ans=0;
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                ans++;
                dfs(list,vis,i);
            }
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends