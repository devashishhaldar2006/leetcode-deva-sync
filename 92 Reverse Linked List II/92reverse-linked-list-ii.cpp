
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right || !head) return head;
        ListNode* a=NULL;
        ListNode* b=NULL;
        ListNode* c=NULL;
        ListNode* d=NULL;
        ListNode* temp=head;
        int n=1;
        while(temp){
            if(n==left-1) a=temp;
            else if(n==left) b=temp;
            else if(n==right) c=temp;
            else if(n==right+1) d=temp;
            n++;
            temp=temp->next;
        }
        if(a) a->next=NULL;
        c->next=NULL;
        c=reverseList(b);
       if(a) a->next=c;
        b->next=d;
        if(a) return head;
        return c;
    }
};