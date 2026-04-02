class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r){
            int sum = numbers[r] + numbers[l];
            if (sum == target){
                return {1+l, 1+r};
            } else if (sum < target) {
                ++l;
            } else if (sum > target){
                --r;
            }
        }
        return {};
    }
};
