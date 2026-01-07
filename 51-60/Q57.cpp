//Q57.cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& n) {
        vector<vector<int>> res;
        int i=0, m=a.size();
        while(i<m && a[i][1]<n[0]) res.push_back(a[i++]);
        while(i<m && a[i][0]<=n[1]){
            n[0]=min(n[0], a[i][0]);
            n[1]=max(n[1], a[i][1]);
            i++;
        }
        res.push_back(n);
        while(i<m) res.push_back(a[i++]);
        return res;
    }
};
