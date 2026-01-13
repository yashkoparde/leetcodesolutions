//separateSquares.cpp
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double lo = 1e9, hi = -1e9;

        for (auto &s: squares) {
            double y = s[1], l = s[2];
            total += l * l;
            lo = min(lo, y);
            hi = max(hi, y + l);
        }

        double target = total / 2.0;

        auto areaAbove = [&](double y0)->double{
            double res = 0;
            for (auto &s: squares) {
                double y = s[1], l = s[2];
                double top = y + l;
                if (y0 <= y) res += l*l;
                else if (y0 < top) res += l * (top - y0);
            }
            return res;
        };

        for (int it = 0; it < 100; ++it) {
            double mid = (lo + hi) / 2.0;
            if (areaAbove(mid) > target) lo = mid;
            else hi = mid;
        }

        return (lo + hi) / 2.0;
    }
};
