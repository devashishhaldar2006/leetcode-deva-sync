class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy=new ListNode(-100);
        ListNode* tempA=list1;
        ListNode* tempB=list2;
        ListNode* tempC=dummy; 
        ListNode* t=dummy; 
        while(tempA && tempB){
            if(tempA->val<tempB->val){
                t->next=tempA;
                tempA=tempA->next;
            }
            else{
                t->next=tempB;
                tempB=tempB->next;
            }
            t=t->next;
            if(tempC->next) tempC=tempC->next;
        }
        if(!tempA){
            tempC->next=tempB;
        }
        else{
            tempC->next=tempA;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        ListNode* c=merge(a,b);
        return c;
    }
};