class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int sizeA=0;
        int sizeB=0;
        while(tempA){
            sizeA++;
            tempA=tempA->next;
        }
        while(tempB){
            sizeB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(sizeB>sizeA){
            for(int i=1;i<=sizeB-sizeA;i++){
                tempB=tempB->next;
            }
        }
        else{
            for(int i=1;i<=sizeA-sizeB;i++){
                tempA=tempA->next;
            }
        }
        while(tempA && tempB){
            if(tempA==tempB) return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};