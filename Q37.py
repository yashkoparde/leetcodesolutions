#Q37.py
class Solution:
    def solveSudoku(self, b):
        row = [0]*9
        col = [0]*9
        box = [0]*9
        empties = []

        for i in range(9):
            for j in range(9):
                if b[i][j] == '.':
                    empties.append((i,j))
                else:
                    v = 1 << (ord(b[i][j]) - 49)
                    row[i] |= v
                    col[j] |= v
                    box[(i//3)*3 + j//3] |= v

        def dfs(k):
            if k == len(empties):
                return True
            i, j = empties[k]
            m = row[i] | col[j] | box[(i//3)*3 + j//3]
            for d in range(9):
                bit = 1 << d
                if not (m & bit):
                    row[i] |= bit
                    col[j] |= bit
                    bx = (i//3)*3 + j//3
                    box[bx] |= bit
                    b[i][j] = chr(d+49)
                    if dfs(k+1): return True
                    row[i] ^= bit
                    col[j] ^= bit
                    box[bx] ^= bit
                    b[i][j] = '.'
            return False

        dfs(0)
