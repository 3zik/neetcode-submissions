class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (const int& num : nums){
            a = a^num;
        }
        return a;
    }
};
