//Q39.cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(const vector<int>& c, int idx, int t){
        if(t==0){
            res.push_back(path);
            return;
        }
        for(int i=idx; i<c.size() && c[i] <= t; i++){
            path.push_back(c[i]);
            dfs(c, i, t - c[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};
