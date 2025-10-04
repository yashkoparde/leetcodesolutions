class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        // Transform S into T with separators to handle even length palindromes
        string t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0); // p[i] = radius of palindrome centered at i
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirror = 2 * center - i; // mirror of i w.r.t center

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            // Expand around center i
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                p[i]++;

            // Update center and right boundary if expanded past right
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        // Find the maximum length palindrome
        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2; // map back to original string
        return s.substr(start, maxLen);
    }
};
