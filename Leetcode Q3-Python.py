int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> seen; // stores last index of characters
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        if (seen.count(c) && seen[c] >= left) {
            // move left pointer right after last duplicate
            left = seen[c] + 1;
        }
        seen[c] = right; // update last index
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
