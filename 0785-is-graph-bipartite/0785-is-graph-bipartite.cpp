class Solution {
public:
    
    bool dfs(vector<int>&color, vector<vector<int>>& graph, int i){
        for(auto x:graph[i]){
            if(color[x]==-1){
                color[x]=!color[i];
                 if(!dfs(color,graph,x))
                     return false;
            }
            if(color[x]==color[i])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(color,graph,i))
                    return false;
            }
        }
        return true;
    }
};