class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r){
            while (l < r && !isAlphaNum(s[r])){
                r--;
            }
            while (l < r && !isAlphaNum(s[l])){
                l++;
            }
            if (tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isAlphaNum(char c){
        return (c >= 'A' && c <= 'Z' ||
                c >= '0' && c <= '9' ||
                c >= 'a' && c <= 'z');
    }
};
