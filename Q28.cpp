class Solution {
public:
    int strStr(string h, string n) {
        int m=n.size(), i=1, k=0;
        vector<int> l(m);
        while(i<m){
            if(n[i]==n[k]) l[i++]=++k;
            else if(k) k=l[k-1];
            else i++;
        }
        i=k=0;
        while(i<h.size()){
            if(h[i]==n[k]) i++,k++;
            else if(k) k=l[k-1];
            else i++;
            if(k==m) return i-m;
        }
        return -1;
    }
};
