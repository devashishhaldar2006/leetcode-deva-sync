class Solution {
public:
    int pairSum(ListNode* head) {
        if(!head) return 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse LL
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        int mx = INT_MIN;
        ListNode* first = head;
        ListNode* second = prev;
        while(second) {
            mx = max(mx, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return mx;
    }
};
