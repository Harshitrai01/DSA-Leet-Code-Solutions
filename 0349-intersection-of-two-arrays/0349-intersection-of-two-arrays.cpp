class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s;
        for(auto x:nums1)
            s.insert(x);
        unordered_set<int>us;
        for(auto x:nums2){
            if(s.find(x)!=s.end()){
                us.insert(x);
            }
        }
        vector<int>ans;
        for(auto x:us)
            ans.push_back(x);
        return ans;
    }
};