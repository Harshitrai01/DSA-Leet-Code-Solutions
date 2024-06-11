class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto x:s){
            st.push(x);
            if(isdigit(x)){
                st.pop();
                if(st.size()>0){
                    st.pop();
                }
            }
        }
        string ans="";
        while(st.size()>0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};