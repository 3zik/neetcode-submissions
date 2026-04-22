class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> check;

        for (int i : nums){
            if (check.contains(i)){
                return true;
            }
            check.insert({i, 1});
        }
        return false;
    }
};