class Solution:
    def checkIfAlphaNum(self, c):
        return ((ord('A') <= ord(c) <= ord('Z')) or (ord('a') <= ord(c) <= ord('z')) or (ord('0') <= ord(c) <= ord('9')))
    def isPalindrome(self, s: str) -> bool:

        s = s.replace(" ", "")
        s = s.lower()

        left = 0
        right = len(s)-1
        while left < right:
            while ((left < right) and (not self.checkIfAlphaNum(s[left]))):
                left = left + 1
            while ((left < right) and (not self.checkIfAlphaNum(s[right]))):
                right = right-1            
            
            if (s[right] != s[left]):
                return False
            
            left +=1
            right -=1

        return True

