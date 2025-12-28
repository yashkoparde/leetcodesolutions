class Solution:
    def groupAnagrams(self, a):
        mp={}
        for s in a:
            k=''.join(sorted(s))
            mp.setdefault(k,[]).append(s)
        return list(mp.values())
