class Solution {
public:
    int romanToInt(string s) {
        int total = 0, prev = 0, val = 0;

        for (int i = (int)s.size() - 1; i >= 0; --i) {
            char c = s[i];
            // direct char-to-value mapping, branch-free via ternaries
            val = (c == 'I') ? 1 :
                  (c == 'V') ? 5 :
                  (c == 'X') ? 10 :
                  (c == 'L') ? 50 :
                  (c == 'C') ? 100 :
                  (c == 'D') ? 500 : 1000;

            total += (val < prev) ? -val : val;
            prev = val;
        }

        return total;
    }
};
