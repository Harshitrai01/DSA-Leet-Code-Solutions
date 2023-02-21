class Solution {
public:
    bool isPal(string s){
        int i=0;
        int j=s.size()-1;
        if(j==-1) return false;
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    
    void solve(vector<vector<string>>&ans,vector<string>&temp,string s,int index){
         if(index==s.size()){
             ans.push_back(temp);
             return;
         }
            
        for(int i=index;i<s.size();i++){
            string op=s.substr(index,i-index+1);
            if(isPal(op)){
                temp.push_back(op);
                solve(ans,temp,s,i+1);
                temp.pop_back();
            }
        }
    }

    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(ans,temp,s,0);
        return ans;
    }
};