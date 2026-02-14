class Solution(object):
    def champagneTower(self, poured, query_row, query_glass):
        dp = [0.0] * 102
        dp[0] = poured

        for i in range(query_row):
            nxt = [0.0] * 102
            for j in range(i + 1):
                if dp[j] > 1.0:
                    extra = (dp[j] - 1.0) / 2.0
                    nxt[j] += extra
                    nxt[j + 1] += extra
            dp = nxt

        if dp[query_glass] > 1.0:
            return 1.0
        return dp[query_glass]