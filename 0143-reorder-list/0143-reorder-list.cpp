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
    void reorderList(ListNode* head) {
        vector<int>nums;
        ListNode*curr=head;
        while(curr!=NULL){
            nums.push_back(curr->val);
            curr=curr->next;
        }
        int i=1,k=0;
        int j=nums.size()-1;
        ListNode*p=new ListNode(-1);
        ListNode*ref=p;
        while(i<=j){
            if(k%2==0){
                ListNode*temp=new ListNode(nums[j]);
                p->next=temp;
                p=temp;
                j--;
            }
                
            else{
                ListNode*temp=new ListNode(nums[i]);
                p->next=temp;
                p=temp;
                i++;
            }
            k++;
        }
        head->next=ref->next;
    }
};