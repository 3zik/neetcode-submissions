class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mp; // val, index
        for (int i = 0; i < nums.size(); ++i){
            if (mp.contains(target - nums[i])){
                return {mp[target-nums[i]], i};
            }
            mp.insert({nums[i], i});
        }
        return {0,0};
    }
};
