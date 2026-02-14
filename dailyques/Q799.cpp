#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(102, 0.0);
        dp[0] = poured;

        for (int i = 0; i < query_row; i++) {
            vector<double> next(102, 0.0);
            for (int j = 0; j <= i; j++) {
                if (dp[j] > 1.0) {
                    double extra = (dp[j] - 1.0) / 2.0;
                    next[j] += extra;
                    next[j + 1] += extra;
                }
            }
            dp.swap(next);
        }

        return min(1.0, dp[query_glass]);
    }
};