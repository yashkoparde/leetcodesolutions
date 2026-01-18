#Q2943.py
class Solution:
    def maximizeSquareHoleArea(self, n, m, h, v):
        def f(a):
            a.sort()
            best = cur = 1
            for i in range(1, len(a)):
                if a[i] == a[i-1] + 1:
                    cur += 1
                else:
                    cur = 1
                best = max(best, cur)
            return best + 1

        side = min(f(h), f(v))
        return side * side
