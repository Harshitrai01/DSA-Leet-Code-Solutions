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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* front=head;
        ListNode* back=head;
        while(front->next!=NULL){
            if(back->val==front->next->val){
                front=front->next;
                if(front->next==NULL){
                    back->next=NULL;
                }
            }   
            else{
                back->next=front->next;
                front=front->next;
                back=back->next;
            }
        }
        return head;
    }
};