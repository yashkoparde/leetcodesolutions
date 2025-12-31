#Q52.py
class Solution:
    def totalNQueens(self, n):
        res=0
        def dfs(r,c,d1,d2):
            nonlocal res
            if r==n:
                res+=1; return
            ok=((1<<n)-1)&~(c|d1|d2)
            while ok:
                p=ok&-ok; ok-=p
                dfs(r+1, c|p, (d1|p)<<1, (d2|p)>>1)
        dfs(0,0,0,0)
        return res
