class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int bot = 0;
        int top = matrix.size() - 1;
        // the "top" of the matrix is higher is number
        // in the first pass, we check the 0th element in the row
        while (bot <= top){
            int mid = bot + (top - bot) / 2;
            if (matrix[mid][0] < target){
                bot = mid + 1;
            } else if (matrix[mid][0] > target) {
                top = mid - 1;
            } else {
                return true;
            }
        }

        if (top < 0) return false;
        
        int row = top;
        int l = 0;
        int r = matrix[row].size() - 1;
        while (l <= r){
            int mid = l + (r - l) / 2;
            if (matrix[row][mid] == target){
                return true;
            } else if (matrix[row][mid] > target) {
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        return false;
    }
};
