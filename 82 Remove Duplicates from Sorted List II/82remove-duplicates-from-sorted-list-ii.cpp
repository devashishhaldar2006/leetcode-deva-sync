
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp=head;
        ListNode* t=new ListNode(-100);
        t->next=head;
        ListNode* s1=t;
        while(temp){
            if(temp->next && temp->val == temp->next->val){
                while(temp->next && temp->val== temp->next->val){
                    temp=temp->next;
                }
                s1->next=temp->next;
            }
            else {
                s1=temp;
            }
            temp=temp->next;
        }
        return t->next;
    }
};