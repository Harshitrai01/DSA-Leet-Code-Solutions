class Solution {
public:
    
    int countbits(int n){
        int count=0;
        while(n!=0){
            n&=(n-1);
            count++;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int bits=countbits(i);
            ans.push_back(bits);
        }
        return ans;
    }
};