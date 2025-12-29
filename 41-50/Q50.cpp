//Q50.cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long p=n;
        if(p<0) x=1/x, p=-p;
        double r=1;
        while(p){
            if(p&1) r*=x;
            x*=x;
            p>>=1;
        }
        return r;
    }
};
