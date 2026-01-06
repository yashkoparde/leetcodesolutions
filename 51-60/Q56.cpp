//Q56.cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        for(auto &v:a){
            if(res.empty() || res.back()[1] < v[0])
                res.push_back(v);
            else
                res.back()[1] = max(res.back()[1], v[1]);
        }
        return res;
    }
};
