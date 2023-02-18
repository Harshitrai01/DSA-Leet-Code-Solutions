class Solution {
public:
    set<vector<int>>s;
    
    void solve(vector<int>&temp, vector<bool>&vis, vector<int>arr, int n){
        if(temp.size()==n){
            s.insert(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vis[i]=true;
                temp.push_back(arr[i]);
                solve(temp,vis,arr,n);
                temp.pop_back();
                vis[i]=false;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int> arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            vis[i]=true;
            temp.push_back(arr[i]);
            solve(temp,vis,arr,n);
            vis[i]=false;
            temp.pop_back();
        }
        for(auto x:s)
            ans.push_back(x);
        return ans;
    }
};