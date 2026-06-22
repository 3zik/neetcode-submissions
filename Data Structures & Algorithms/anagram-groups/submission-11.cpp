class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;

        for (string s : strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; ++i){
                key += '#' + count[i];
            }
            hash[key].push_back(s);
        }
        for (const auto& pair : hash){
            res.push_back(pair.second);
        }
        return res;
    }
};
