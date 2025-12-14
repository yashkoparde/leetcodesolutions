#Q40.py
class Solution:
    def combinationSum2(self, c, target):
        c.sort()
        res, path = [], []

        def dfs(i, t):
            if t == 0:
                res.append(path[:])
                return
            prev = -1
            for j in range(i, len(c)):
                if c[j] > t: break
                if c[j] == prev: continue
                prev = c[j]
                path.append(c[j])
                dfs(j+1, t - c[j])
                path.pop()

        dfs(0, target)
        return res
