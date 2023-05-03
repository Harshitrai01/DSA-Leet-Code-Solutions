class Solution {
public:
    void dfs(int s, int d, vector<vector<int>> adj, vector<int>vis, vector<vector<int>> &ans, vector<int>temp){
        
        vis[s]=1;
        temp.push_back(s);
        if(s==d){
            ans.push_back(temp);
        }
        for(auto x:adj[s]){
            if(!vis[x]){
                dfs(x,d,adj,vis,ans,temp);
            }
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>vis(V,0);
        dfs(0,V-1,graph,vis,ans,temp);
        return ans;
        
    }
};