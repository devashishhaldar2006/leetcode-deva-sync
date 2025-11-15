class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode* curr = head;
        int count = 0;
        while (curr && count < 2) {
            curr = curr->next;
            count++;
        }
        if(count<2) return head;
        ListNode* newHead = swapNodes(head, 2);
        head->next = swapPairs(curr);

        return newHead;
        
        
    }
};