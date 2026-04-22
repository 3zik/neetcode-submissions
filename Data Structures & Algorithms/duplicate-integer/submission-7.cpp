class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> check;

        for (int i : nums){
            if (check.contains(i)){
                return true;
            }
            check.insert({i});
        }
        return false;
    }
};