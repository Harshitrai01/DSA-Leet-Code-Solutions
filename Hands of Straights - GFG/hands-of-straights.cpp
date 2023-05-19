//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) {
        
        if(n%groupSize!=0) return false;
        
        map<int,int>mp;
        for(auto x:hand){
            mp[x]++;
        }
        int x=n/groupSize;
        vector<vector<int>>check(x,vector<int>(groupSize,-1));
        int p=0,q=0;
        while(mp.size()!=0){
            for(auto x:mp){
                check[p][q]=x.first;
                mp[x.first]--;
                if(mp[x.first]==0)
                    mp.erase(x.first);
                q++;
                if(q==groupSize){
                    p++;q=0;
                    break;
                }
            }
        }
        
        for(int i=0;i<check.size();i++){
            for(int j=1;j<check[0].size();j++){
                if(check[i][j]-check[i][j-1]!=1)
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends