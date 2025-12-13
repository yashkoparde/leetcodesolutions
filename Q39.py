#Q39.py
class Solution:
    def combinationSum(self, c, target):
        c.sort()
        res, path = [], []

        def dfs(i, t):
            if t == 0:
                res.append(path[:])
                return
            for j in range(i, len(c)):
                if c[j] > t: break
                path.append(c[j])
                dfs(j, t - c[j])
                path.pop()

        dfs(0, target)
        return res


