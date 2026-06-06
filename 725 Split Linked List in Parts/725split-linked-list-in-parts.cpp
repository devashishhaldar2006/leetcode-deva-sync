class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        temp=head;
        int rem=n%k;
        int size=n/k;
        while(temp){
            ListNode* dummy=new ListNode(-100);
            ListNode* t=dummy;
            int s=size;
            if(rem>0) s++;
            rem--;
            for(int i=1;i<=s;i++){
                t->next=temp;
                t=t->next;
                if(temp) temp=temp->next;

            }
            if(t) t->next=NULL;
            ans.push_back(dummy->next);
        }
        while(ans.size()!=k ){
            ans.push_back(NULL);
        }
        return ans;
    }
};