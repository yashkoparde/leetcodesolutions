//Q2975.cpp
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        const long long MOD = 1e9+7;
        h.push_back(1); h.push_back(m);
        v.push_back(1); v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<int> hs;
        for(int i=0;i<h.size();i++)
            for(int j=i+1;j<h.size();j++)
                hs.insert(h[j]-h[i]);

        long long best = -1;
        for(int i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++){
                int d = v[j]-v[i];
                if(hs.count(d)) best = max(best, (long long)d);
            }

        if(best==-1) return -1;
        return (best*best)%MOD;
    }
};
