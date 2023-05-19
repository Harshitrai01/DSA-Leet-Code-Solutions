class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int>ms;
        for(auto x:matrix)
            for(auto y:x)
                ms.insert(y);
            
        auto it=next(ms.begin(),k-1);
        return *it;
    }
};