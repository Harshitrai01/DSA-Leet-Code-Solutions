class Solution {
public:
    set<string>st;
    void solve(string ip, string op){
        if(ip.length()==0){
            st.insert(op);
            return;
        }
        string op1=op,op2=op;
        if(isdigit(ip[0])){
            op1.push_back(ip[0]);
            op2.push_back(ip[0]); 
        }
        else{
            op1.push_back(ip[0]);
            if(islower(ip[0]))
                op2.push_back(toupper(ip[0]));      
            else
                op2.push_back(tolower(ip[0]));
        }
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);
        return;
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string op="";
        solve(s,op);
        for(auto x:st)
                ans.push_back(x);
        return ans;
    }
};