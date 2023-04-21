//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(vector<vector<char>>&grid, string word, int i, int j, int d1, int d2, int s){
	    int n=grid.size();
	    int m=grid[0].size();
        if(s==word.size())
            return true;
        int r=i+d1;
        int c=j+d2;
        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s])
            return dfs(grid,word,r,c,d1,d2,s+1);
        
        return false;
    }
        
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans;
        int drow[8]={0,-1,-1,-1,0,1,1,1};
        int dcol[8]={-1,-1,0,1,1,1,0,-1};
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
                    for(int k=0;k<8;k++){
                        if(dfs(grid,word,i,j,drow[k],dcol[k],1)){
        	               ans.push_back({i,j});
        	               break;
                        }
                    }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends