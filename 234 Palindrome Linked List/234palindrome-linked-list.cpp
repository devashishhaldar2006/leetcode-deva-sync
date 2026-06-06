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
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=reverseList(slow->next);
        slow=head;
        while(slow && rev){
            if(slow->val!=rev->val) return false;
            slow=slow->next;
            rev=rev->next;
        }
        return true;
    }
};