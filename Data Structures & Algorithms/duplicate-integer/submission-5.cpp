class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;

        for (int i : nums) {
            if (mySet.contains(i)) {
                return true;
            }
                mySet.insert(i);
        }
        return false;
    }
};