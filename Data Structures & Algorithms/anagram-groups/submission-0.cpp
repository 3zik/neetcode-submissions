class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto &s : strs){ //auto here bceause we want it to be a str and int at same time
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++; // maps to 0-26 here, since 'a' is 97, 'a' now becomes 0, and 'z' is 26
            }
            string key = to_string(count[0]); // kind of just making a tuple/string as the key
            for (int i = 1; i < 26; ++i){
                key += ',' + to_string(count[i]);
            }

            res[key].push_back(s); 
            /*
                key = 01010101... correspoinding to letter freq
                res[key] = [list of words with this key]
                res[key].push_back(s) appends s to this list 
            */
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
