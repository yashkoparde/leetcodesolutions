#Q45.py
class Solution:
    def jump(self, a):
        jumps = 0
        curEnd = 0
        far = 0
        for i in range(len(a)-1):
            far = max(far, i + a[i])
            if i == curEnd:
                jumps += 1
                curEnd = far
        return jumps
