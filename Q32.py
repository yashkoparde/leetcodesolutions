#Q32.py
class Solution:
    def longestValidParentheses(self, s):
        st=[-1]; best=0
        for i,ch in enumerate(s):
            if ch=='(':
                st.append(i)
            else:
                st.pop()
                if not st:
                    st.append(i)
                else:
                    best=max(best, i-st[-1])
        return best
