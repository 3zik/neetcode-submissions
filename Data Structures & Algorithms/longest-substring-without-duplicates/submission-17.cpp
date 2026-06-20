class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> hash_map;
        int l = 0;
        int maxLen = 0;
        
        for(int r = 0; r < s.size(); ++r){
            while (hash_map.count(s[r])){
                hash_map.erase(s[l]);
                l++;
            }
            hash_map[s[r]] = 1;
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
