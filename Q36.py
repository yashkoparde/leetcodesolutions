#Q36.py
class Solution:
    def isValidSudoku(self, b):
        row = [[0]*9 for _ in range(9)]
        col = [[0]*9 for _ in range(9)]
        box = [[0]*9 for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if b[i][j] == '.': continue
                v = ord(b[i][j]) - 49
                k = (i//3)*3 + j//3
                if row[i][v] or col[j][v] or box[k][v]:
                    return False
                row[i][v] = col[j][v] = box[k][v] = 1
        return True
