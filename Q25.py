#Q25.py
class Solution:
    def reverseKGroup(self, head, k):
        dummy = ListNode(0, head)
        prevGroupEnd = dummy

        while True:
            kth = prevGroupEnd
            for _ in range(k):
                kth = kth.next
                if not kth:
                    return dummy.next

            groupStart = prevGroupEnd.next
            nextGroupStart = kth.next

            # Reverse group
            prev, curr = nextGroupStart, groupStart
            while curr != nextGroupStart:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp

            prevGroupEnd.next = kth
            prevGroupEnd = groupStart
