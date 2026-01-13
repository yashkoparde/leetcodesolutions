#Q3027.py
class Solution:
    def separateSquares(self, s):
        ys=set()
        for x,y,l in s:
            ys.add(y)
            ys.add(y+l)
        ys=sorted(list(ys))
        m=len(ys)

        diff=[0.0]*m
        import bisect
        
        for x,y,l in s:
            a=bisect.bisect_left(ys,y)
            b=bisect.bisect_left(ys,y+l)
            diff[a]+=l
            diff[b]-=l

        for i in range(1,m):
            diff[i]+=diff[i-1]

        total=0.0
        for i in range(m-1):
            total+=diff[i]*(ys[i+1]-ys[i])

        half=total/2.0
        pref=0.0
        
        for i in range(m-1):
            h=ys[i+1]-ys[i]
            seg=diff[i]*h
            if pref+seg>=half:
                need=half-pref
                return ys[i]+need/diff[i]
            pref+=seg
        
        return ys[-1]
