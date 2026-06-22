class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        // each key is a 26 length tuple representing char freq
        for (const auto& s : strs){
            vector<int> count(26,0);
            for (char c : s){
                count[c - 'a']++;
                // index a @ 0, b @ 1, etc.
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i){
                key+= ',' + to_string(count[i]);
            }
            // create a key like: 1,0,1,1,0,0,0 ...etc
            
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res){
            result.push_back(pair.second);
        }
        return result;
    }
};
