class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxLen = 0;
        std::unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); ++r){
            while (mp.count(s[r])){
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]] = 1;
            maxLen = std::max(r - l + 1, maxLen);
        }
        return maxLen;
    }
};
