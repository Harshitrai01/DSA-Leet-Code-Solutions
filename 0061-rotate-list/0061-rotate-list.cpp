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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        ListNode* first=head;
        ListNode* last=head;
        int n=1;
        while(last->next!=NULL){
            last=last->next;
            n++;
        }
        k=k%n;
        int loop=0;
        while(loop<n-k-1){
            first=first->next;
            loop++;
        }
        last->next=head;
        ListNode *newhead=first->next;
        first->next=NULL;

        return newhead;
    }
};