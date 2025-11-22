//Q25.cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;

        while (true) {
            ListNode* kth = prevGroupEnd;
            // Find the k-th node
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break; // not enough nodes

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroupStart = kth->next;

            // Reverse k nodes
            ListNode *prev = nextGroupStart, *curr = groupStart;
            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect reversed group with previous part
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};
