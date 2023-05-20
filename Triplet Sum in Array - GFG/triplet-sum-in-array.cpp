//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        unordered_set<int>us;
        map<int,int>mp1;
    
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int to_search=X-(A[i]+A[j]);
                if(us.find(to_search)!=us.end())
                    return true;
                else{
                    us.insert(A[j]);
                }
            }
            us.clear();
            us.insert(A[i]);
        }
        
        return false;
        
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends