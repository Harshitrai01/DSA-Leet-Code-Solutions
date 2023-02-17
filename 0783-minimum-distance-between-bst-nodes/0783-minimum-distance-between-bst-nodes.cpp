/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMin(vector<int>v,int val){
        int mn=INT_MAX;
        for(int i=0;i<v.size();i++){
                mn=min(mn,abs(v[i]-val));
        }
        return mn;
    }
    void solve(vector<int>v,int &mn, TreeNode* root){
        if(root!=NULL){
            v.push_back(root->val);
            if(root->left!=NULL){
                int val=getMin(v,root->left->val);
                mn=min(mn,val);
            }
            if(root->right!=NULL){
                int val=getMin(v,root->right->val);
                mn=min(mn,val);
            }
            solve(v,mn,root->left);
            solve(v,mn,root->right);
        }   
            
    }
    
    int minDiffInBST(TreeNode* root) {
        int mn=INT_MAX;
        vector<int>v;
        solve(v,mn,root);
        return mn;
    }
};