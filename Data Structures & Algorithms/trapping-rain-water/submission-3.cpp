class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int r = height.size() - 1;
        int l = 0;
        int rightMax = height[r];
        int leftMax = height[l];
        int res = 0;

        while (l < r){
            if (leftMax < rightMax){
                l++;
                leftMax = max(height[l], leftMax);
                res += leftMax - height[l];
            } else {
                r--;
                rightMax = max(height[r], rightMax);
                res += rightMax - height[r];
            }
            
        }
        return res;
    }
};
