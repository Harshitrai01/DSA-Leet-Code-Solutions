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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
           int s=0;
           ListNode*curr=head;
           
           while(curr!=NULL){
               curr=curr->next;
               s++;
           }
           
           int f=s-n;
           f--;
           ListNode* curr1=head;
           while(f>0){
               curr1=curr1->next;
               f--;
           }
           if(f==-1){
               return head->next;
           }
           
           curr1->next=curr1->next->next;
            
           return head;
    }
};