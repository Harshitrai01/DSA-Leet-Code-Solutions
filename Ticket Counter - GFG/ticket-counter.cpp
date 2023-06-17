//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        deque<int>dq;
        for(int i=1;i<=N;i++){
            dq.push_back(i);
        }
        int ans=0;
        while(dq.size()){
            int var=K;
            while(var-- and dq.size()){
                ans=dq.front();
                dq.pop_front();
            }
            var=K;
            while(var-- and dq.size()){
                ans=dq.back();
                dq.pop_back();
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends