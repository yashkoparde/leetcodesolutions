//Q29.cpp
class Solution {
public:
    int divide(int a, int b) {
        if(a==INT_MIN && b==-1) return INT_MAX;
        long x=labs(a), y=labs(b), r=0;
        while(x>=y){
            long t=y, m=1;
            while((t<<1)<=x) t<<=1, m<<=1;
            x-=t; r+=m;
        }
        return (a>0)^(b>0) ? -r : r;
    }
};
