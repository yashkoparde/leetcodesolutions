#Q30.py
class Solution:
    def findSubstring(self, s, w):
        n=len(s); m=len(w); L=len(w[0]); tot=m*L
        need={}
        for x in w: need[x]=need.get(x,0)+1
        res=[]
        for off in range(L):
            win={}; cnt=0; l=off
            for r in range(off, n-L+1, L):
                t=s[r:r+L]
                if t in need:
                    win[t]=win.get(t,0)+1; cnt+=1
                    while win[t]>need[t]:
                        u=s[l:l+L]; win[u]-=1; l+=L; cnt-=1
                    if cnt==m:
                        res.append(l)
                        u=s[l:l+L]; win[u]-=1; l+=L; cnt-=1
                else:
                    win.clear(); cnt=0; l=r+L
        return res
