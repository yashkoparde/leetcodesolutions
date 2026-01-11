//Q85.cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        vector<int> h(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) h[j]= (matrix[i][j]=='1')? h[j]+1:0;
            stack<int> st; vector<int> l(n), r(n);
            for(int j=0;j<n;j++){
                while(!st.empty() && h[st.top()]>=h[j]) st.pop();
                l[j]= st.empty()? -1: st.top();
                st.push(j);
            }
            while(!st.empty()) st.pop();
            for(int j=n-1;j>=0;j--){
                while(!st.empty() && h[st.top()]>=h[j]) st.pop();
                r[j]= st.empty()? n: st.top();
                st.push(j);
            }
            for(int j=0;j<n;j++) ans=max(ans,h[j]*(r[j]-l[j]-1));
        }
        return ans;
    }
};
