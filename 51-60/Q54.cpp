//Q54.cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int t=0,b=m.size()-1,l=0,r=m[0].size()-1;
        vector<int> res;
        while(t<=b && l<=r){
            for(int j=l;j<=r;j++) res.push_back(m[t][j]);
            t++;
            for(int i=t;i<=b;i++) res.push_back(m[i][r]);
            r--;
            if(t<=b){
                for(int j=r;j>=l;j--) res.push_back(m[b][j]);
                b--;
            }
            if(l<=r){
                for(int i=b;i>=t;i--) res.push_back(m[i][l]);
                l++;
            }
        }
        return res;
    }
};
