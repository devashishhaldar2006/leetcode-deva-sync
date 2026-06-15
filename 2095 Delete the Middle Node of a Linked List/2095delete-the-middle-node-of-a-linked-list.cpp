class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL ||  head->next==NULL) return NULL;
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        temp=head;
        for(int i=1;i<size/2;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};