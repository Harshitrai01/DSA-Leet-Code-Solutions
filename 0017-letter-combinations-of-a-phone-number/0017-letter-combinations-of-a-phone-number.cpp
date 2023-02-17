class Solution {
public:
    vector<string>words={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void solve(vector<string>& ans, int n, string op, int iter, string digits){
        if(n==0){
            ans.push_back(op);
            return;
        }
        
        for(int i=0;i<words[int(digits[iter]-48)].size();i++){
            char ch=words[int(digits[iter]-48)][i];
            op.push_back(ch);
            solve(ans,n-1,op,iter+1,digits);
            op.pop_back();
        }
        
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string>ans;
        if(n==0)
            return ans;
        string op="";
        solve(ans,n,op,0,digits);
        return ans;
    }
};