class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxf = 0;
        int res = 0;
        std::unordered_map<char, int> mp;

        for (int r = 0; r < s.size(); ++r){
            mp[s[r]]++;
            maxf = std::max(mp[s[r]], maxf);
            while ((r - l + 1) - maxf > k) {
                mp[s[l]]--;
                l++;
            }
            res = std::max(res, (r - l + 1));
        }
        return res;
    }
};
