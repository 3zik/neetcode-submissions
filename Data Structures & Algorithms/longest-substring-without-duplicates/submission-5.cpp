class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxLen = 0;

        unordered_map<char, int> check;
        
        for (int r = 0; r < s.size(); r++){
            while (check.count(s[r])){
                check.erase(s[l]);
                l++;
            }
            check[s[r]] = 1;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
