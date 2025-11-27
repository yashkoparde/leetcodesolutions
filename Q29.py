#Q29.py
class Solution:
    def divide(self, a, b):
        if a==-2**31 and b==-1: return 2**31-1
        x=abs(a); y=abs(b); r=0
        while x>=y:
            t=y; m=1
            while t<<1 <= x:
                t <<= 1; m <<= 1
            x -= t; r += m
        return -r if (a>0)^(b>0) else r
