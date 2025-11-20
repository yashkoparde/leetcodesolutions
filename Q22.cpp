//Q22.cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        cur.reserve(n * 2);
        dfs(n, n, cur, res);
        return res;
    }
    void dfs(int o, int c, string& cur, vector<string>& res) {
        if (!o && !c) { res.push_back(cur); return; }
        if (o) {
            cur.push_back('(');
            dfs(o-1, c, cur, res);
            cur.pop_back();
        }
        if (c > o) {
            cur.push_back(')');
            dfs(o, c-1, cur, res);
            cur.pop_back();
        }
    }
};
