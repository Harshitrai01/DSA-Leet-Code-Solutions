//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string>ans;
        for(auto x:Dictionary){
            int pi=0;
                for(int i=0;i<x.size() and pi<Pattern.size();i++){
                    if(Pattern[pi]!=x[i] and x[i]>='A' and x[i]<='Z'){
                        break;
                    }
                    if(Pattern[pi]==x[i]){
                        pi++;
                    }
                }
                if(pi==Pattern.size()){
                    ans.push_back(x);
                }
            
        }
        if(ans.size()==0) ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends