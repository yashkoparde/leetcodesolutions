//Q44.cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int star = -1, match = 0;

        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++; j++;                     // direct match
            }
            else if (j < p.size() && p[j] == '*') {
                star = j++;                  // record star position
                match = i;                   // match start
            }
            else if (star != -1) {           // backtrack to last star
                j = star + 1;
                i = ++match;
            }
            else return false;
        }

        while (j < p.size() && p[j] == '*') j++;  // trailing *

        return j == p.size();
    }
};
