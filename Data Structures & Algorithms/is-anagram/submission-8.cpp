class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> check1;
        unordered_map<char, int> check2;

        for (char s_char : s) {
            check1[s_char]++;
        }

        for (char t_char : t) {
            check2[t_char]++;    
        }

        return check1 == check2;
    }
};
