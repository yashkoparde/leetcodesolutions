#Q42.py
class Solution:
    def trap(self, h):
        l, r = 0, len(h)-1
        lm = rm = ans = 0
        while l < r:
            if h[l] < h[r]:
                if h[l] >= lm: lm = h[l]
                else: ans += lm - h[l]
                l += 1
            else:
                if h[r] >= rm: rm = h[r]
                else: ans += rm - h[r]
                r -= 1
        return ans
