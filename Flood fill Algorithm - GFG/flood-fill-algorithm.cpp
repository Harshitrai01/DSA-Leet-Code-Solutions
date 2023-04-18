//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    void dfs(vector<vector<int>>&image, int sr, int sc, int source, int color){
        int n=image.size(),m=image[0].size();
        int drow[]={0,0,1,-1};
        int dcol[]={-1,1,0,0};
        image[sr][sc]=color;
        for(int k=0;k<=3;k++){
            int i=sr+drow[k];
            int j=sc+dcol[k];
            if(i>=0 and i<n and j>=0 and j<m and image[i][j]==source)
                dfs(image,i,j,source,color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int source=image[sr][sc];
        if(source==newColor) return image;
        dfs(image,sr,sc,source,newColor);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends