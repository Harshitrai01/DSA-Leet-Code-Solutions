class Solution {
public:
    bool isPalindrome(string S){
        
    for (int i=0; i<S.length()/2;i++){
        if (S[i]!=S[S.length()-i-1]){
            return false;
        }
    }
    return true;
}
    string firstPalindrome(vector<string>& words) {
        for(auto x:words){
            if(isPalindrome(x))
                return x;
        }
        return "";
    }
};