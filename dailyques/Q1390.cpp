//Q1390.cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) {
            int s = 1 + x, cnt = 2;
            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    int e = x / d;
                    cnt += (d == e ? 1 : 2);
                    s += (d == e ? d : d + e);
                    if (cnt > 4) break;
                }
            }
            if (cnt == 4) ans += s;
        }
        return ans;
    }
};
