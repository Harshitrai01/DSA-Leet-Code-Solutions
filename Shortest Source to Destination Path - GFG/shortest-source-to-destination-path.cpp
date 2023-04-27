//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>>grid, int x, int y) {
        queue< pair< pair<int,int>,int> >q;
        
        if(grid[x][y]==1)
        q.push({{x,y},0});
        
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        int ans=-1;
        
        while(!q.empty()){
            
            int i=q.front().first.first;
            int j=q.front().first.second;
            int level=q.front().second;
            q.pop();
            if(i==0 and j==0){
                ans=level;
                return ans;
            }
            for(int k=0;k<4;k++){
                int r=drow[k]+i;
                int c=dcol[k]+j;
                if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1){
                    q.push({{r,c},level+1});
                    // marking vis so it doesn't repeats 1 again
                    grid[r][c]=0;
                }
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends