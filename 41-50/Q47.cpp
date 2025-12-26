class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> res;
        sort(a.begin(), a.end());
        do res.push_back(a);
        while(next_permutation(a.begin(), a.end()));
        return res;
    }
};
