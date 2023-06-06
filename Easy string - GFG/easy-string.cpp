//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string s){
    s+='.';
    string ans="";
    string temp="";
    temp+=tolower(s[0]);
    for(int i=1;i<s.size();i++){
        if(temp.back()==tolower(s[i]))
            temp+=tolower(s[i]);
        else{
            ans+=to_string(temp.size());
            ans+=temp.back();
            temp="";
            temp+=tolower(s[i]);
        }
    }
    return ans;
}

