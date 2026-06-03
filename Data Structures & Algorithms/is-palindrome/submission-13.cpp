class Solution {
public:
    bool isAlpha(char ch) { // return 0 if not alphanum
        return std::isalnum(static_cast<unsigned char>(ch));
    }
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r){
            while (l < r && !isAlpha(s[l])) {
                l++;
            }
            while (l < r && !isAlpha(s[r])) {
                r--;
            }
            if (tolower(static_cast<unsigned char>(s[l]))
                 == tolower(static_cast<unsigned char>(s[r]))) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;  
    }
};
