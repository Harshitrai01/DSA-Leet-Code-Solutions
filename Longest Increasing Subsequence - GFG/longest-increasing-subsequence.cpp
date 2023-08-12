//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    
    int ceilIdx(int tail[], int l, int h, int x){
        while(l<h){
            int m=l+(h-l)/2;
            if(tail[m]>=x)
                h=m;
            else
                l=m+1;
        }
        return h;
    }
    
    
    int longestSubsequence(int n, int arr[])
    {
        int tail[n],len=1;
        tail[0]=arr[0];
        
        for(int i=1;i<n;i++){
            
            if(arr[i]>tail[len-1]){
                tail[len]=arr[i];
                len++;
            }
            
            else{
                int c=ceilIdx(tail,0,len-1,arr[i]);
                tail[c]=arr[i];
            }
                
        }
        return len;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends