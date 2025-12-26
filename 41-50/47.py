class Solution:
    def permuteUnique(self, a):
        a.sort()
        res=[a[:]]
        while True:
            i=len(a)-2
            while i>=0 and a[i]>=a[i+1]: i-=1
            if i<0: break
            j=len(a)-1
            while a[j]<=a[i]: j-=1
            a[i],a[j]=a[j],a[i]
            a[i+1:]=reversed(a[i+1:])
            res.append(a[:])
        return res
