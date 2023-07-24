class Solution {
public:
    void bfs(vector<int>adj[],vector<int>&vis,int i){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adj[node]){
                if(vis[x]==0){
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ans++;
                bfs(adj,vis,i);
            }
        }
        return ans;
    }
};