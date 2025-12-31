//Q52.cpp
class Solution {
public:
    int totalNQueens(int n) {
        int res=0;
        function<void(int,int,int,int)> dfs = [&](int r,int c,int d1,int d2){
            if(r==n){ res++; return; }
            int ok=((1<<n)-1)&~(c|d1|d2);
            while(ok){
                int p=ok&-ok; ok-=p;
                dfs(r+1, c|p, (d1|p)<<1, (d2|p)>>1);
            }
        };
        dfs(0,0,0,0);
        return res;
    }
};
