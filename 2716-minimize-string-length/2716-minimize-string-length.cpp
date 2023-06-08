class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_set<char>us;
        for(auto x:s) us.insert(x);
        return us.size();
    }
};