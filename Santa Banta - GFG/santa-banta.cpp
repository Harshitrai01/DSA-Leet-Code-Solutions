//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int> primes;
    void precompute(){
        SieveOfEratosthenes(primes);
    }
    void SieveOfEratosthenes(vector<int>& primes)
    {   int N = 2000000;
        bool IsPrime[N];
        memset(IsPrime, true, sizeof(IsPrime));
     
        for (int p = 2; p * p <N; p++) {
            if (IsPrime[p] == true) {
                for (int i = p * p; i <N; i += p)
                    IsPrime[i] = false;
            }
        }
        for (int p = 2; p <N; p++)
            if (IsPrime[p])
                primes.push_back(p);
    }
    
    
    
    void dfs(int i, int n, int m, vector<vector<int>> &g, vector<int>&vis, int &ans){
        vis[i]=1;
        for(auto x:g[i]){
            if(!vis[x]){
                ans++;
                dfs(x,n,m,g,vis,ans);
            }
        }
    }

    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<int>vis(n+1,0);
        int k=-1;
        for(int i=1;i<=n;i++){
            int ans=0;
            if(!vis[i]){
                ans=1;
                dfs(i,n,m,g,vis,ans);
                k=max(ans,k);
            }
        }
        if(k==-1 or k-1<=0) return -1;
        
        return primes[k-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends