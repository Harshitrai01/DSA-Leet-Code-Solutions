//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isPossible(int n, vector<pair<int, int> >& arr) {
        
        vector<int> adj[n];
        for(int i=0; i<arr.size(); i++){
            adj[arr[i].first].push_back(arr[i].second);
        }
        
        vector<int> inDeg(n, 0);
        
        for(int i=0; i<n; i++){
            for(auto j: adj[i]){
                inDeg[j]++;
            }
        }
        
        vector<int> topo;
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto j: adj[node]){
                inDeg[j]--;
                if(inDeg[j] == 0){
                    q.push(j);
                }
            }
        }
        
        return (topo.size() == n);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends