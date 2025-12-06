//Q34.cpp
class Solution {
public:
    int lb(vector<int>& a,int t){
        int l=0,r=a.size();
        while(l<r){
            int m=(l+r)>>1;
            if(a[m]<t) l=m+1;
            else r=m;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& a, int t) {
        int L=lb(a,t);
        if(L==a.size() || a[L]!=t) return {-1,-1};
        int R=lb(a,t+1)-1;
        return {L,R};
    }
};

