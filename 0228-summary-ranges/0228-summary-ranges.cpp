class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n=nums.size();
        if(n==0) return ans;
        if(n==1){
            ans.push_back(to_string(nums[0]));
        }
        int start=nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i]+1!=nums[i+1]){
                if((start==nums[i] and start+1<nums[i+1])){
                    ans.push_back(to_string(start));
                    start=nums[i+1];    
                }
                else{
                    string s=to_string(start)+"->"+to_string(nums[i]);
                    ans.push_back(s);
                    start=nums[i+1];                    
                }
            }
            if(i==n-2 and start==nums[i+1]){
                ans.push_back(to_string(start));
            }
            else if(i==n-2 and nums[i]+1==nums[i+1]){
                string s=to_string(start)+"->"+to_string(nums[i+1]);
                ans.push_back(s);
            }
        }
        cout<<start<<endl;
        return ans;
    }
};