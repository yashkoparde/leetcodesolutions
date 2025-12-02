//Q32.cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size(), best=0;
        vector<int> st; st.push_back(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push_back(i);
            else{
                st.pop_back();
                if(st.empty()) st.push_back(i);
                else best=max(best, i-st.back());
            }
        }
        return best;
    }
};
