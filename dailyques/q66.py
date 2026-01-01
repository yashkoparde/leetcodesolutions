#Q66.py
class Solution:
    def plusOne(self, a):
        for i in range(len(a)-1, -1, -1):
            if a[i] < 9:
                a[i] += 1
                return a
            a[i] = 0
        return [1] + a
