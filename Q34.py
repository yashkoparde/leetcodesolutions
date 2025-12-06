#Q34.py
class Solution:
    def searchRange(self, a, t):
        def lb(x):
            l=0; r=len(a)
            while l<r:
                m=(l+r)//2
                if a[m]<x: l=m+1
                else: r=m
            return l
        L=lb(t)
        if L==len(a) or a[L]!=t: return [-1,-1]
        R=lb(t+1)-1
        return [L,R]
