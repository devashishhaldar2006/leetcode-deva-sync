class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy=new ListNode(-100);
        ListNode* prev=dummy;
        ListNode* cur=head;
        while (cur) {
            ListNode* nextNode =cur->next;
            if (prev->val >= cur->val) {
                prev = dummy;
            }

            while (prev->next && prev->next->val < cur->val) {
                prev = prev->next;
            }

            cur->next = prev->next;
            prev->next = cur;

            cur = nextNode;
        }

        return dummy->next;
    }
};
