#Q35.py
class Solution:
    def searchInsert(self, a, t):
        l=0; r=len(a)
        while l<r:
            m=(l+r)//2
            if a[m]<t: l=m+1
            else: r=m
        return l
