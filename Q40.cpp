//Q40.cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(const vector<int>& c, int idx, int t){
        if(t == 0){
            res.push_back(path);
            return;
        }
        for(int i = idx; i < c.size(); i++){
            if(c[i] > t) break;
            if(i > idx && c[i] == c[i-1]) continue; // skip duplicates
            path.push_back(c[i]);
            dfs(c, i+1, t - c[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return res;
    }
};
