class Solution {
public:
    bool detectCapitalUse(string word) {
        
        // 1st char is small
        if(word[0]>=97 and word[0]<=122){
            for(int i=1;i<word.size();i++){
                if(word[i]>=65 and word[i]<=90)
                    return false;
            }
        }
        
        // 1st char is large
        else if(word[0]>=65 and word[0]<=90){
            if(word.size()>1 and word[1]>=97 and word[1]<=122)
            for(int i=2;i<word.size();i++){
                if(word[i]>=65 and word[i]<=90)
                    return false;
            }  
            else if(word.size()>1 and word[1]>=65 and word[1]<=90)
            for(int i=2;i<word.size();i++){
                if(word[i]>=97 and word[i]<=122)
                    return false;
            } 
        }
        
        return true;
        
    }
};