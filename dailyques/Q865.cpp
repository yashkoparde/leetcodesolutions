//Q865.cpp
class Solution {
public:
    pair<TreeNode*,int> dfs(TreeNode* root){
        if(!root) return {nullptr,0};
        auto L=dfs(root->left), R=dfs(root->right);
        if(L.second==R.second) return {root,L.second+1};
        return (L.second>R.second)? make_pair(L.first,L.second+1)
                                  : make_pair(R.first,R.second+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        return dfs(root).first;
    }
};
