//Q30.cpp
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        int n=s.size(), m=w.size(), L=w[0].size(), tot=m*L;
        unordered_map<string,int> need;
        for(auto &x:w) need[x]++;
        vector<int> res;
        for(int off=0; off<L; off++){
            int cnt=0; unordered_map<string,int> win;
            for(int l=off, r=off; r+L<=n; r+=L){
                string t=s.substr(r,L);
                if(need.count(t)){
                    win[t]++; cnt++;
                    while(win[t]>need[t]){
                        win[s.substr(l,L)]--; l+=L; cnt--;
                    }
                    if(cnt==m){
                        res.push_back(l);
                        win[s.substr(l,L)]--; l+=L; cnt--;
                    }
                } else {
                    win.clear(); cnt=0; l=r+L;
                }
            }
        }
        return res;
    }
};
