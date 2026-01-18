#Q3047.py
class Solution:
    def largestSquareArea(self, bl, tr):
        n = len(bl)
        ans = 0
        for i in range(n):
            for j in range(i+1, n):
                x1 = max(bl[i][0], bl[j][0])
                y1 = max(bl[i][1], bl[j][1])
                x2 = min(tr[i][0], tr[j][0])
                y2 = min(tr[i][1], tr[j][1])
                if x2 > x1 and y2 > y1:
                    side = min(x2-x1, y2-y1)
                    ans = max(ans, side*side)
        return ans
