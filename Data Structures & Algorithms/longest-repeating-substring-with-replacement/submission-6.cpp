class Solution {
public:
    int characterReplacement(string s, int k) {
        // valid window as long as:
        // window size - count of most freq. char <= k

        int l = 0;
        std::unordered_map<char, int> count;
        int res = 0;
        int maxf = 0; // most frequent char in the window
        
        for (int r = 0; r < s.size(); ++r) {
            count[s[r]]++;
            maxf = std::max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
