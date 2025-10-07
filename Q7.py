class Solution:
    def reverse(self, x):
        INT_MAX, INT_MIN = 2**31 - 1, -2**31
        rev, sign = 0, 1 if x >= 0 else -1
        x = abs(x)

        while x:
            pop = x % 10
            x //= 10
            if rev > INT_MAX // 10 or (rev == INT_MAX // 10 and pop > 7):
                return 0
            rev = rev * 10 + pop

        return sign * rev
