class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        unordered_map<int,pair<int,int>>mp;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        
        unordered_map<int,int>m_row;
        unordered_map<int,int>m_col;
        
        for(int i=0;i<arr.size();i++){
            pair<int,int>p=mp[arr[i]];
            
            int r=p.first;
            int c=p.second;
            
            m_row[r]++;
            m_col[c]++;
            
            if(m_row[r]>=m) return i;
            if(m_col[c]>=n) return i;
        }
        
        return -1;
    }
};