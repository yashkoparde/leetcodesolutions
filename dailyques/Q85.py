#Q85.py
class Solution(object):
    def maximalRectangle(self, matrix):
        m,n=len(matrix),len(matrix[0])
        h=[0]*n; ans=0
        for i in range(m):
            for j in range(n):
                h[j]=h[j]+1 if matrix[i][j]=='1' else 0
            st=[]; l=[0]*n; r=[0]*n
            for j in range(n):
                while st and h[st[-1]]>=h[j]: st.pop()
                l[j]=st[-1] if st else -1
                st.append(j)
            st=[]
            for j in range(n-1,-1,-1):
                while st and h[st[-1]]>=h[j]: st.pop()
                r[j]=st[-1] if st else n
                st.append(j)
            for j in range(n):
                ans=max(ans,h[j]*(r[j]-l[j]-1))
        return ans
