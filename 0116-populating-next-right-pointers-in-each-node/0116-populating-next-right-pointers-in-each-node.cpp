/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
    if(root!=NULL){
                queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                
                Node *temp=q.front(); q.pop();
                
                if(temp->left!=NULL)
                    q.push(temp->left);
                
                if(temp->right!=NULL)
                    q.push(temp->right); 
                
                if(i==size-1){
                    temp->next=NULL;
                }
                else{
                    Node* new_temp=q.front();
                    temp->next=new_temp;
                }
            }

        }
    }return root;
    }
};