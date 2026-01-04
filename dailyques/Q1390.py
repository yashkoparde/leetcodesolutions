class Solution:
    def sumFourDivisors(self, nums):
        ans = 0
        for x in nums:
            s, cnt = 1 + x, 2
            d = 2
            while d * d <= x:
                if x % d == 0:
                    e = x // d
                    cnt += 1 if d == e else 2
                    s += d if d == e else d + e
                    if cnt > 4: break
                d += 1
            if cnt == 4: ans += s
        return ans
