class Solution {
public:
    int search(vector<int>& nums, int target) {
        int right = nums.size();
        int left = 0;
        int mid = right / 2;
        while (left <= right) {
            if (nums[mid] > target) {
                right = mid-1;
                mid = left + (right-left) / 2;
            } else if (nums[mid] < target) {
                left = mid+1;
                mid = left + (right-left) / 2;
            } else {
                return mid;
            }
        }
        
        return -1;

    }
};
