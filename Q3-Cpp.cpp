class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // stores last index of each ASCII char
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1; // move left after the duplicate
            }
            lastIndex[c] = right; // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
