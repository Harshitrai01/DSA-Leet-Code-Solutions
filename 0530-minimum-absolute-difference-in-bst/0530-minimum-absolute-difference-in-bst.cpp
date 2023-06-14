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
    void solve(vector<int>&v, TreeNode* root){
        if(root!=NULL){
            solve(v,root->left);
            v.push_back(root->val);
            solve(v,root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int mn=1e9;
        vector<int>v;
        solve(v,root);
        for(int i=0;i<v.size()-1;i++){
            mn=min(mn,abs(v[i]-v[i+1]));
        }
        return mn;
    }
};