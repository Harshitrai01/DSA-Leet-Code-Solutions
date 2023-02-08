//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      vector<long long>ans;
      long long freecell=n*n;
      long long row_count=0,col_count=0;
      vector<long long>r(n,0),c(n,0);
      for(int i=0;i<k;i++){
          int row=arr[i][0]-1, col=arr[i][1]-1;
          if(c[col]==0){
              col_count++;
              c[col]=1;
              freecell=freecell-n+row_count;
          }
          if(r[row]==0){
              row_count++;
              r[row]=1;
              freecell=freecell-n+col_count;
          }
          ans.push_back(freecell);
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends