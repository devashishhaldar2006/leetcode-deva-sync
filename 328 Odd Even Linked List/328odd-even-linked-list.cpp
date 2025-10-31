
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tempA=new ListNode(100);
        ListNode* tempB=new ListNode(200);
        ListNode* s=head;
        ListNode* tA=tempA;
        ListNode* tB=tempB;
        int k=1;
        while(s){
            if(k%2!=0){
                tA->next=s;
                tA=tA->next;
            }
            else {
                tB->next=s;
                tB=tB->next;
            }
            s=s->next;
            k++;
        }
        tB->next = NULL;   
        tA->next = tempB->next;

        return tempA->next;  
        
    }
};