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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        
        int ans=1;
        int sum=root->val;
        int curr_sum=root->val;
        
        while(!q.empty()){
            int level=q.front().second;
            int size=q.size();
            if(curr_sum>sum){
                ans=level;
                sum=curr_sum;
            }
            curr_sum=0;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front().first;
                if(curr->left!=NULL){
                    q.push({curr->left,level+1});
                    curr_sum+=curr->left->val;
                }
                if(curr->right!=NULL){
                    q.push({curr->right,level+1});
                    curr_sum+=curr->right->val;
                }
                q.pop();
            }
        }
        return ans;
    }
};