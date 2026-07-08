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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;
        while(lists.size()>1){
            ListNode* a=lists[0];
            lists.erase(lists.begin());
            ListNode* b=lists[0];
            lists.erase(lists.begin());
            ListNode* c=merge(a,b);
            lists.push_back(c);
        }
        return lists[0];
    }
};