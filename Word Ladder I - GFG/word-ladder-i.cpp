//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string>us;
        
        for(auto x:wordList)
            us.insert(x);
            
        queue<pair<string,int>>q;
        q.push({startWord,1});
        us.erase(startWord);
        
        while(!q.empty()){
            string s=q.front().first;
            int level=q.front().second;
            q.pop();
            if(s==targetWord)
                return level;
            for(int i=0;i<s.size();i++){
                char original=s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i]=ch;
                    if(us.find(s)!=us.end()){
                        q.push({s,level+1});
                        us.erase(s);
                    }
                }
                s[i]=original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends