class Solution:
    def maxArea(self, h):
        l, r, ans = 0, len(h) - 1, 0
        while l < r:
            hl, hr = h[l], h[r]
            if hl < hr:
                ans = max(ans, hl * (r - l))
                l += 1
            else:
                ans = max(ans, hr * (r - l))
                r -= 1
        return ans
