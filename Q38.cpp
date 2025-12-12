//Q38.cpp
// C++ — fastest / minimal allocations
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        while(--n){
            string t;
            t.reserve(s.size()*2);
            for(int i=0;i<s.size();){
                int j = i;
                while(j<s.size() && s[j]==s[i]) j++;
                t += char('0' + (j-i));
                t += s[i];
                i = j;
            }
            s.swap(t);
        }
        return s;
    }
};
