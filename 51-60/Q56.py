#Q56.py
class Solution:
    def merge(self, a):
        a.sort()
        res=[]
        for s,e in a:
            if not res or res[-1][1] < s:
                res.append([s,e])
            else:
                res[-1][1] = max(res[-1][1], e)
        return res
