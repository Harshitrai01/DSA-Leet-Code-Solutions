class Solution {
public:
    
    bool isVowel(char ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u'){
            return true;
        }
        return false;
    }
    
    int maxVowels(string s, int k) {
        int ans=-1e9;
        int n=s.size();
        
        int count=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i]))
                count++;
            ans=max(ans,count);
        }
        
        int i=0;
        int j=k;
        while(j<n){
            if(isVowel(s[j]))
                count++;
            if(isVowel(s[i]))
                count--;
            i++;j++;
            ans=max(ans,count);
        }
        
        return ans;
    }
};