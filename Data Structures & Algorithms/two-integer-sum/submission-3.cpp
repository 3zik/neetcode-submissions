class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash; // key:number, value:index

        for (int i=0; i<nums.size(); i++) {
            if (hash.contains(target-nums[i])){
                return {hash.at(target-nums[i]), i};
            } else {
                hash.insert({nums[i], i});
            }
        }
    }
};
