#Q51.py
class Solution:
    def solveNQueens(self, n):
        res=[]; b=[['.']*n for _ in range(n)]
        def dfs(r,c,d1,d2):
            if r==n:
                res.append([''.join(x) for x in b]); return
            ok=((1<<n)-1)&~(c|d1|d2)
            while ok:
                p=ok&-ok; ok-=p
                j=0
                while (1<<j)!=p: j+=1
                b[r][j]='Q'
                dfs(r+1, c|p, (d1|p)<<1, (d2|p)>>1)
                b[r][j]='.'
        dfs(0,0,0,0)
        return res
