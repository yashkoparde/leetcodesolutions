class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* t = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) t->next = l1, l1 = l1->next;
            else t->next = l2, l2 = l2->next;
            t = t->next;
        }
        t->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
