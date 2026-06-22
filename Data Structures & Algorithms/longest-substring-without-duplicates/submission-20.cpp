class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        unordered_map<char, int> mp;
        int maxLen = 0;
        for (int r = 0; r < s.size(); ++r){
            while (mp.count(s[r])){
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]] = 1;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
