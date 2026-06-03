class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int l = 0;
        int maxf = 0;
        std::unordered_map<char, int> count;

        // window is ok as long as:
        // window size >= k + maxf
        // window size - maxf >= k
        // so: invalid when window size - maxf < k

        for (int r = 0; r < s.size(); ++r) {
            count[s[r]]++; //add 1 to count for s[r]
            maxf = std::max(maxf, count[s[r]]);
            
            // check validity
            while ((r - l + 1) - maxf > k) {
                // just move up l
                count[s[l]]--; // remove 1 instance of l
                l++;
            }
            res = std::max(res, (r - l + 1));
        }
        return res;
    }
};
