//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        x--;y--;
        vector<vector<int>>matrix(n,vector<int>(m,0));
        queue<pair <pair<int,int>, int>>q;
        matrix[x][y]=1;
        q.push({{x,y},0});
        
        int ans=0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int level=q.front().second;
            q.pop();
            int drow[]={0,0,1,-1};
            int dcol[]={1,-1,0,0};
            for(int k=0;k<4;k++){
                int r=drow[k]+i;
                int c=dcol[k]+j;
                if(r>=0 and r<n and c>=0 and c<m and matrix[r][c]==0){
                    matrix[r][c]=1;
                    q.push({{r,c},level+1});
                    ans=max(ans,level+1);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends