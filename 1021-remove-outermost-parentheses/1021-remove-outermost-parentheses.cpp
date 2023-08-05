class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(auto x:s){
            if(x=='(')
                cnt++;
            if(cnt>1)
                ans+=x;
            if(x==')')
                cnt--;
        }
        return ans;
    }
};