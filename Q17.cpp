class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        static const vector<string> pad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> res;
        string cur;
        cur.reserve(digits.size());
        dfs(digits, 0, cur, res, pad);
        return res;
    }
private:
    void dfs(const string& d, int i, string& cur, vector<string>& res, const vector<string>& pad) {
        if (i == d.size()) { res.push_back(cur); return; }
        const string& letters = pad[d[i] - '0'];
        for (char c : letters) {
            cur.push_back(c);
            dfs(d, i + 1, cur, res, pad);
            cur.pop_back();
        }
    }
};
