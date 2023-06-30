class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else{
            long long num=0;
            long long original=x;
            while(x!=0){
                int ld=x%10;
                num=num*10+ld;
                x=x/10;
            }
            // cout<<num;
            return (num==original);
        }
    }
};