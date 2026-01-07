#Q1339.py
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxProduct(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        MOD = 10**9 + 7

        def sums(node):
            if not node: return 0
            return node.val + sums(node.left) + sums(node.right)

        total = sums(root)
        self.ans = 0

        def dfs(node):
            if not node: return 0
            s = node.val + dfs(node.left) + dfs(node.right)
            self.ans = max(self.ans, s * (total - s))
            return s

        dfs(root)
        return self.ans % MOD
