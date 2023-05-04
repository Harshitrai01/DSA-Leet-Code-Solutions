class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int>us;
        for(auto x:nums){
            us.insert(x);
        }
        vector<int>ans;
        for(int i=1;i<=nums.size();i++){
            if(us.find(i)==us.end())
                ans.push_back(i);
        }
        
        return ans;
    }
};