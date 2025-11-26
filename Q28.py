class Solution:
    def strStr(self, h, n):
        m=len(n); l=[0]*m; i=1; k=0
        while i<m:
            if n[i]==n[k]: k+=1; l[i]=k; i+=1
            elif k: k=l[k-1]
            else: i+=1
        i=0; k=0
        while i<len(h):
            if h[i]==n[k]: i+=1; k+=1
            elif k: k=l[k-1]
            else: i+=1
            if k==m: return i-m
        return -1
