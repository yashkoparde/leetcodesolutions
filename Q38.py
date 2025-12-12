#Q38.py
class Solution:
    def countAndSay(self, n: int) -> str:
        s = "1"
        for _ in range(n-1):
            t = []
            i = 0
            L = len(s)
            while i < L:
                j = i+1
                while j < L and s[j] == s[i]:
                    j += 1
                t.append(str(j-i))
                t.append(s[i])
                i = j
            s = "".join(t)
        return s
