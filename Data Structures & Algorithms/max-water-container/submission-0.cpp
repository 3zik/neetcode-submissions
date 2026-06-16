class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxA = 0;
        int r = heights.size() - 1;
        int l = 0;
        while (l < r){
            int height = min(heights[l], heights[r]);
            int curr = height * (r - l);
            maxA = max(maxA, curr);
            if (heights[l] > heights[r]){
                r--;
            }
            else {
                l++;
            }
        }
        return maxA;
    }
};
