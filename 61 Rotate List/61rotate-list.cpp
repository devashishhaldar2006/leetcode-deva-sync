class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n=0;
        ListNode* temp=head;
        ListNode* t=head;
        while(temp){
            n++;
            if(t->next) t=t->next;
            temp=temp->next;
        }
        k=k%n;
        temp=head;
        for(int i=1;i<n-k;i++){
            temp=temp->next;
        }
        t->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;


    }
};