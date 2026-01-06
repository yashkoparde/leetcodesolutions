//Q1161.cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 1, best = 1;
        long long mx = LLONG_MIN;
        while (!q.empty()) {
            int sz = q.size();
            long long sum = 0;
            while (sz--) {
                auto n = q.front(); q.pop();
                sum += n->val;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            if (sum > mx) mx = sum, best = lvl;
            lvl++;
        }
        return best;
    }
};
