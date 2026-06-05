class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* lo=new ListNode(-100);
        ListNode* hi=new ListNode(-200);
        ListNode* tl=lo;
        ListNode* th=hi;
        ListNode* t=head;
        while(t){
            if(t->val<x){
                tl->next=t;
                t=t->next;
                tl=tl->next;
            }
            else{
                th->next=t;
                t=t->next;
                th=th->next;
            }
        }
        th->next=NULL;
        tl->next=hi->next;
        return lo->next;

    }
};