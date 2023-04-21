//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool diagLeft1(vector<vector<char>>&grid, string word, int i, int j, int s){
	    int n=grid.size();
	    int m=grid[0].size();
        if(s==word.size())
            return true;
        int r=i-1;
        int c=j+1;
        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
            if(diagLeft1(grid,word,r,c,s+1))
                return true;
        }
        return false;
    }
    
    bool diagRight1(vector<vector<char>>&grid, string word, int i, int j, int s){
	    int n=grid.size();
	    int m=grid[0].size();
        if(s==word.size())
            return true;
        int r=i-1;
        int c=j-1;
        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
            if(diagRight1(grid,word,r,c,s+1))
                return true;
        }
        return false;
    }
    
    bool diagLeft(vector<vector<char>>&grid, string word, int i, int j, int s){
	    int n=grid.size();
	    int m=grid[0].size();
        if(s==word.size())
            return true;
        int r=i+1;
        int c=j-1;
        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
            if(diagLeft(grid,word,r,c,s+1))
                return true;
        }
        return false;
    }
    
    bool diagRight(vector<vector<char>>&grid, string word, int i, int j, int s){
	    int n=grid.size();
	    int m=grid[0].size();
        if(s==word.size())
            return true;
        int r=i+1;
        int c=j+1;
        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
            if(diagRight(grid,word,r,c,s+1))
                return true;
        }
        return false;
    }
    
    bool Right(vector<vector<char>>&grid, string word, int i, int j, int s){
	    int n=grid.size();
	    int m=grid[0].size();
        if(s==word.size())
            return true;
        int r=i;
        int c=j+1;
        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
            if(Right(grid,word,r,c,s+1))
                return true;
        }
        return false;
    }

    bool Right1(vector<vector<char>>&grid, string word, int i, int j, int s){
    	    int n=grid.size();
    	    int m=grid[0].size();
            if(s==word.size())
                return true;
            int r=i;
            int c=j-1;
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
                if(Right1(grid,word,r,c,s+1))
                    return true;
            }
            return false;
        }
        
    bool Up(vector<vector<char>>&grid, string word, int i, int j, int s){
    	    int n=grid.size();
    	    int m=grid[0].size();
            if(s==word.size())
                return true;
            int r=i+1;
            int c=j;
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
                if(Up(grid,word,r,c,s+1))
                    return true;
            }
            return false;
        }
        
    bool Down(vector<vector<char>>&grid, string word, int i, int j, int s){
    	    int n=grid.size();
    	    int m=grid[0].size();
            if(s==word.size())
                return true;
            int r=i-1;
            int c=j;
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==word[s]){
                if(Down(grid,word,r,c,s+1))
                    return true;
            }
            return false;
        }
        
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>ans;
	    vector<int>temp;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
                    if(diagRight(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
                    else if(diagLeft(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
                    else if(diagLeft1(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
                    else if(diagRight1(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
                    else if(Right(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
                    else if(Right1(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
                    else if(Up(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
                    else if(Down(grid,word,i,j,1)){
	                    temp.push_back(i);
	                    temp.push_back(j);
                    }
	            }
    	        if(temp.size()==2){
                    ans.push_back(temp);
    	            temp.clear();	            
    	        }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends