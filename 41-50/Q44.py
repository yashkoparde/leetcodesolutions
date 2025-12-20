#Q44.py
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i = j = 0
        star = -1
        match = 0

        while i < len(s):
            if j < len(p) and (p[j] == s[i] or p[j] == '?'):
                i += 1
                j += 1
            elif j < len(p) and p[j] == '*':
                star = j
                j += 1
                match = i
            elif star != -1:
                j = star + 1
                match += 1
                i = match
            else:
                return False

        while j < len(p) and p[j] == '*':
            j += 1

        return j == len(p)
