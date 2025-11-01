class Solution {
public:
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int count = 0;
        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return head;
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count < k) return head;
        ListNode* newHead = reverseKNodes(head, k);
        head->next = reverseKGroup(curr, k);

        return newHead;
    }
};
