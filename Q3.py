class Solution(object):
    def lengthOfLongestSubstring(self, s):
        seen = {}
        left = 0
        max_len = 0
    
        for right, char in enumerate(s):
        # If character is already seen and is inside the current window
            if char in seen and seen[char] >= left:
                left = seen[char] + 1  # move left pointer right after the duplicate
        
            seen[char] = right  # update last seen index of char
            max_len = max(max_len, right - left + 1)
    
        return max_len
        
