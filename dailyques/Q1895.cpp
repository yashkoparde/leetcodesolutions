//Q1895.cpp
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size();
        vector<vector<int>> r(m+1, vector<int>(n+1)), c=r, d1=r, d2=r;
        for(int i=0;i<m;i++)for(int j=0;j<n;j++){
            r[i+1][j+1]=r[i+1][j]+g[i][j];
            c[i+1][j+1]=c[i][j+1]+g[i][j];
            d1[i+1][j+1]=d1[i][j]+g[i][j];
            d2[i+1][j+1]=d2[i][j+2]+g[i][j];
        }
        for(int k=min(m,n);k>=2;k--){
            for(int i=0;i+k<=m;i++)for(int j=0;j+k<=n;j++){
                int s=r[i+1][j+k]-r[i+1][j];
                bool ok=1;
                for(int x=0;x<k&&ok;x++)
                    ok&=(r[i+x+1][j+k]-r[i+x+1][j]==s)&&
                        (c[i+k][j+x+1]-c[i][j+x+1]==s);
                ok&=(d1[i+k][j+k]-d1[i][j]==s)&&
                    (d2[i+k][j+1]-d2[i][j+k+1]==s);
                if(ok) return k;
            }
        }
        return 1;
    }
};
