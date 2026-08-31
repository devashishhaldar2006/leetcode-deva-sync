class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx=1;
        int firstMaxIdx=-1;
        int secondMaxIdx=-1;
        int firstMinIdx=-1;
        int secondMinIdx=-1;
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;
        if(!c) return {-1,-1};
        int maxDistance=0;
        int minDistance=INT_MAX;
        while(c){
            if((b->val>c->val && b->val>a->val) || (b->val<c->val && b->val<a->val)){
                if(firstMaxIdx==-1){
                    firstMaxIdx=idx;
                }
                else{
                    secondMaxIdx=idx;
                }
                firstMinIdx=secondMinIdx;
                secondMinIdx=idx;
                if(firstMinIdx!=-1) minDistance=min(minDistance,secondMinIdx-firstMinIdx);
                
            }
            idx++;
            a=a->next;
            b=b->next;
            c=c->next;
        }
        if(secondMaxIdx==-1) return {-1,-1};
        maxDistance=secondMaxIdx-firstMaxIdx;
        return {minDistance,maxDistance};
    }
};