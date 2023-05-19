class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
	    vector<int> adj[N];
	    for(auto i: prerequisites){
	        adj[i[1]].push_back(i[0]);
	    }
	    
	    vector<int>inDeg(N,0);
	    
	    for(int i=0;i<N;i++){
	        for(auto j :adj[i]){
	            inDeg[j]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        if(inDeg[i]==0) q.push(i);
	    }
	    
	    int count=0;
	    while(!q.empty()){
	        count++;
	        int u=q.front();
	        q.pop();
	        for(auto x:adj[u]){
	            inDeg[x]--;
	            if(inDeg[x]==0)
	                q.push(x);
	        }
	    }
	    
	    if(count==N) return true;
	    return false;
    }
};