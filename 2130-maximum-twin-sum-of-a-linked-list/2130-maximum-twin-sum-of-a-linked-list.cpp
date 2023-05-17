/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>v;
        ListNode* curr=head;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        int i=0;
        int j=v.size()-1;
        int ans=-1e9;
        while(i<j){
            ans=max(ans,v[i]+v[j]);
            i++;j--;
        }
        return ans;
    }
};