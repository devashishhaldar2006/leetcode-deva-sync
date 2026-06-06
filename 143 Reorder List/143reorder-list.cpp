class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* prev=NULL;
        ListNode* nxt=NULL;
        ListNode* curr=head;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=reverseList(slow->next);
        slow->next=NULL;
        ListNode* dummy=new ListNode(-100);
        ListNode* t=dummy;
        ListNode* a=head;
        while(a && rev){
           t->next=a;
           a=a->next;
           t=t->next;

           t->next=rev;
           rev=rev->next;
           t=t->next;
        }
        t->next=a;
        head=dummy->next;
        return;

    }
};