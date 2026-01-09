#Q865.py
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        def dfs(node):
            if not node: return (None,0)
            l,dl=dfs(node.left); r,dr=dfs(node.right)
            if dl==dr: return (node,dl+1)
            return (l,dl+1) if dl>dr else (r,dr+1)
        return dfs(root)[0]
