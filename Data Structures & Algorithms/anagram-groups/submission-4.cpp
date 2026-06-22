class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        vector<vector<string>> result;

        for (const auto& s : strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++;
            }
            string key = "";
            for (int i = 0; i < 26; ++i){
                key += "#" + to_string(count[i]);
            }
            hash[key].push_back(s);
        }
        for (const auto& pair : hash){
            result.push_back(pair.second);
        }
        return result;
    }
};
