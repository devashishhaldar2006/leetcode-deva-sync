class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* tempA=head;
        int n=0;
        while(tempA){
            n++;
            tempA=tempA->next;
        }
        int m=n-k+1;
        tempA=head;
        ListNode* tempB=head;
        for(int i=1;i<k;i++){
            tempA=tempA->next;
        }
        for(int i=1;i<m;i++){
            tempB=tempB->next;
        }
        swap(tempA->val,tempB->val);
        return head;
        
        
    }
};