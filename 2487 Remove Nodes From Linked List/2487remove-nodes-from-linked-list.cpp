class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head) return NULL;
        head= reverseLL(head);
        stack<int> ans;
        int maxVal=head->val; 
        ans.push(maxVal);
        ListNode* temp=head->next;

        while(temp){
            if(temp->val>=maxVal){
                maxVal=temp->val;
                ans.push(maxVal);
            }
            temp=temp->next;
        }

        ListNode* newHead=NULL;
        while(ans.size()){
            ListNode* node = new ListNode(ans.top());
            ans.pop();
            node->next = newHead;
            newHead = node;
        }

        return reverseLL(newHead);
    }
};
