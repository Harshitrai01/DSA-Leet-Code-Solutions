class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>adjRev[V];
        vector<int>indeg(V,0);
        for(int i=0;i<V;i++){
            // i->it;
            // it->i;Reversing the edges
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }
        
        queue<int>q;
        vector<int>safeNodes;
        for(int i=0;i<V;i++){
            if(indeg[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto x:adjRev[node]){
                indeg[x]--;
                if(indeg[x]==0)
                q.push(x);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};