class Solution {
public:
    bool isValid(string x) {
     stack<int> s;
        for(int i=0;i<x.length();i++){
            
            if(x[i]=='[' or x[i]=='{' or x[i]=='('){
                s.push(x[i]);
            }
            
            else{
                if(s.empty()==true){
                    return false;
                }
                
                else if(matching(s.top(),x[i])==false){
                    return false;
                }
                
                else
                    s.pop();
            }
        }
        
        return (s.empty()==true);
    }
    
    bool matching(char a, char b){
        return(
            (a=='(' and b==')') or
            (a=='[' and b==']') or
            (a=='{' and b=='}')
            );
    }
};