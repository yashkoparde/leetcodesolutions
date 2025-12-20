#Q43.py
class Solution:
    def multiply(self, a: str, b: str) -> str:
        if a == "0" or b == "0":
            return "0"
        n, m = len(a), len(b)
        res = [0]*(n+m)

        for i in range(n-1, -1, -1):
            x = ord(a[i]) - 48
            for j in range(m-1, -1, -1):
                y = ord(b[j]) - 48
                s = res[i+j+1] + x*y
                res[i+j+1] = s % 10
                res[i+j] += s // 10

        i = 0
        while i < len(res) and res[i] == 0:
            i += 1
        return "".join(str(d) for d in res[i:])
