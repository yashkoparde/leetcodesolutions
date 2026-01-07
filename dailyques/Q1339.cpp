//Q1339.cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long total = 0, best = 0;
    const long long MOD = 1000000007;

    long long sum(TreeNode* r){
        if(!r) return 0;
        return r->val + sum(r->left) + sum(r->right);
    }
    long long dfs(TreeNode* r){
        if(!r) return 0;
        long long s = r->val + dfs(r->left) + dfs(r->right);
        best = max(best, s * (total - s));
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = sum(root);
        dfs(root);
        return best % MOD;
    }
};
