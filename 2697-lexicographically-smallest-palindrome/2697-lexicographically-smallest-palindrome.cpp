class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        int i=0,j=n-1;
        string ans1="";
        string ans2="";
        while(i<=j){
            if(s[i]!=s[j]){
                if(s[i]<s[j]){
                    ans1+=s[i];
                    ans2+=s[i];
                }    
                else{
                    ans1+=s[j];
                    ans2+=s[j];
                }
                
            }
            else{
                if(s[i]<s[j]){
                    ans1+=s[i];
                    ans2+=s[i]; 
                }
                else{
                    ans1+=s[j];
                    ans2+=s[j];
                }
            }
            i++;j--;
        }
        if(n%2==1) ans2.erase((n/2));
        reverse(ans2.begin(),ans2.end());
        return ans1+ans2;
    }
};