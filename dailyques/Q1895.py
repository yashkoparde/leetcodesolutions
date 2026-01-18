#Q1895.py
class Solution:
    def largestMagicSquare(self, g):
        m,n=len(g),len(g[0])
        r=[[0]*(n+1) for _ in range(m+1)]
        c=[[0]*(n+1) for _ in range(m+1)]
        d1=[[0]*(n+1) for _ in range(m+1)]
        d2=[[0]*(n+2) for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                r[i+1][j+1]=r[i+1][j]+g[i][j]
                c[i+1][j+1]=c[i][j+1]+g[i][j]
                d1[i+1][j+1]=d1[i][j]+g[i][j]
                d2[i+1][j+1]=d2[i][j+2]+g[i][j]
        for k in range(min(m,n),1,-1):
            for i in range(m-k+1):
                for j in range(n-k+1):
                    s=r[i+1][j+k]-r[i+1][j]
                    ok=True
                    for x in range(k):
                        if r[i+x+1][j+k]-r[i+x+1][j]!=s or \
                           c[i+k][j+x+1]-c[i][j+x+1]!=s:
                            ok=False; break
                    if ok and d1[i+k][j+k]-d1[i][j]==s and \
                       d2[i+k][j+1]-d2[i][j+k+1]==s:
                        return k
        return 1
