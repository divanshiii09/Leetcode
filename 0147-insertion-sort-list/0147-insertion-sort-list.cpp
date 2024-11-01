class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode temp(0);
        ListNode* cur = head;

        while (cur) {
            ListNode* prev = &temp;
            while (prev->next && prev->next->val < cur->val) {
                prev = prev->next;
            }
            ListNode* next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = next;
        }

        return temp.next;
    }
};
