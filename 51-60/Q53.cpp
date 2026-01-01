//Q53.cpp
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int cur=a[0], best=a[0];
        for(int i=1;i<a.size();i++){
            cur = max(a[i], cur + a[i]);
            best = max(best, cur);
        }
        return best;
    }
};
