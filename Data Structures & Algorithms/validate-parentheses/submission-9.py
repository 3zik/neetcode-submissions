class Solution:
    def isValid(self, s: str) -> bool:
        myStack = [] #[(

        for i in range(len(s)):
            if s[i] == "[" or s[i] == "{" or s[i] == "(":
                myStack.append(s[i]) # push to stack
            else:
                # peek
                if len(myStack) == 0:
                    return False
                if ((s[i]=="]") and ("[" != myStack[-1])):
                    return False
                if ((s[i]==")") and ("(" != myStack[-1])):
                    return False
                if ((s[i]=="}") and ("{" != myStack[-1])):
                    return False
                else:
                    myStack.pop()
        if len(myStack) == 0:
            return True
        else: 
            return False