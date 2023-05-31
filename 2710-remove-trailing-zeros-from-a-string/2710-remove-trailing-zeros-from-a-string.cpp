class Solution {
public:
    string removeTrailingZeros(string num) {
        string ans="";
        int n=num.size();
        bool flag=true;
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0' and flag==true){
                continue;
            }
            else{
                flag=false;
                ans+=num[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};