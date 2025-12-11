//Q37.cpp
class Solution {
public:
    bool row[9][9]{}, col[9][9]{}, box[9][9]{};

    bool dfs(vector<vector<char>>& b, int i=0, int j=0){
        if(i==9) return true;
        if(j==9) return dfs(b, i+1, 0);
        if(b[i][j] != '.') return dfs(b, i, j+1);

        int k = (i/3)*3 + j/3;
        for(int v=0; v<9; v++){
            if(!row[i][v] && !col[j][v] && !box[k][v]){
                row[i][v] = col[j][v] = box[k][v] = true;
                b[i][j] = char(v+'1');
                if(dfs(b, i, j+1)) return true;
                b[i][j] = '.';
                row[i][v] = col[j][v] = box[k][v] = false;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& b) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(b[i][j] != '.'){
                    int v = b[i][j] - '1';
                    row[i][v] = col[j][v] = box[(i/3)*3 + j/3][v] = true;
                }
        dfs(b);
    }
};
