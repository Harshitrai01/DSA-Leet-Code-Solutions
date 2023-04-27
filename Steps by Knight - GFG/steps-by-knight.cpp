//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    queue< pair< pair<int,int>,int> >q;
	    vector<vector<int>>grid(n,vector<int>(n,0));
	    
	    int kx=KnightPos[0]-1;
	    int ky=KnightPos[1]-1;
	    
	    int tx=TargetPos[0]-1;
	    int ty=TargetPos[1]-1;
	    
	    grid[kx][ky]=1;
	    q.push({{kx,ky},0});
	    
        int drow[]={-2,-2,-1,-1, 1,1, 2,2};
        int dcol[]={-1, 1,-2, 2,-2,2,-1,1};
	    
	    while(!q.empty()){
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        int level=q.front().second;
	        q.pop();
	        
	        if(i==tx and j==ty){
	            return level;
	        }
	        
	        for(int k=0;k<8;k++){
	            int r=i+drow[k];
	            int c=j+dcol[k];
	            if(r>=0 and r<n and c>=0 and c<n and grid[r][c]==0){
	                q.push({{r,c},level+1});
	                grid[r][c]=1;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends