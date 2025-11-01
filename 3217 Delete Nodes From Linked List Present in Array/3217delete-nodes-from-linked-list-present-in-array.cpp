class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return head;
        unordered_map<int, int> m;
        for (auto num : nums) {
            m[num] = 1;
        }
        ListNode* dummy = new ListNode(-100); 
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {
            if (m.find(curr->val) != m.end()) {
                prev->next = curr->next;
            } else {
                prev = curr; 
            }
            curr = curr->next;
        }

        return dummy->next;
    }
};
