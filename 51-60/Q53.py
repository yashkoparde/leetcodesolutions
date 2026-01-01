#Q53.py
class Solution:
    def maxSubArray(self, a):
        cur = best = a[0]
        for x in a[1:]:
            cur = max(x, cur + x)
            best = max(best, cur)
        return best
