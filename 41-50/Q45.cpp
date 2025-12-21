//Q45.cpp
class Solution {
public:
    int jump(vector<int>& a) {
        int jumps = 0, curEnd = 0, far = 0;
        for(int i = 0; i < a.size()-1; i++){
            far = max(far, i + a[i]);
            if(i == curEnd){
                jumps++;
                curEnd = far;
            }
        }
        return jumps;
    }
};
