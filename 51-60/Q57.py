#Q57.py
class Solution:
    def insert(self, a, n):
        res=[]; i=0; m=len(a)
        while i<m and a[i][1]<n[0]:
            res.append(a[i]); i+=1
        while i<m and a[i][0]<=n[1]:
            n[0]=min(n[0], a[i][0])
            n[1]=max(n[1], a[i][1])
            i+=1
        res.append(n)
        while i<m:
            res.append(a[i]); i+=1
        return res
