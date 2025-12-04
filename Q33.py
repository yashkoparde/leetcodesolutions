#Q33.py
class Solution:
    def search(self, a, t):
        l=0; r=len(a)-1
        while l<=r:
            m=(l+r)//2
            if a[m]==t: return m
            if a[l]<=a[m]:
                if a[l]<=t<a[m]: r=m-1
                else: l=m+1
            else:
                if a[m]<t<=a[r]: l=m+1
                else: r=m-1
        return -1
