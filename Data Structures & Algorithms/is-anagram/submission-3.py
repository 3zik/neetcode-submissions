class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(t) != len(s):
            return False
        for i in range(len(s)):
            for j in range(len(t)):
                if t[j] == s[i]:
                    t = t[:j] + t[j+1:] 
                    break
        if t != "":
            return False
        else:
            return True