//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int n=hospital.size();
        int m=hospital[0].size();
        
        queue< pair<pair<int,int>,int> >q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hospital[i][j]==2)
                    q.push({{i,j},0});
            }
        }
        
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        int ans=-1e9;
        
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int level=q.front().second;
            q.pop();
            ans=max(ans,level);
            for(int k=0;k<4;k++){
                int r=drow[k]+i;
                int c=dcol[k]+j;
                if(r>=0 and r<n and c>=0 and c<m and hospital[r][c]==1){
                    q.push({{r,c},level+1});
                    hospital[r][c]=2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(hospital[i][j]==1)
                    return -1;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends