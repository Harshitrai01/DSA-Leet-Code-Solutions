class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat.size();j++){
                if(i==j or i==mat.size()-j-1){
                    cout<<mat[i][j]<<endl;
                    sum+=mat[i][j];
                }
            }
        }
            
        return sum;
    }
};