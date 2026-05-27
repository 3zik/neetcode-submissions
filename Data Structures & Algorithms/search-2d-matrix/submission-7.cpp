class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Bin search for mins of each row
        int rows = matrix.size();
        int cols = matrix[0].size();

        int upper = 0; // upper and lower indices
        int lower = matrix.size() - 1; // number of rows
        int mid;
        while (upper <= lower){
            mid = upper + (lower - upper) / 2;

            if (target < matrix[mid][0]){
                lower = mid - 1;
            } else if (target > matrix[mid][cols-1]) {
                upper = mid + 1;
            } else {
                // we're in the correct row
                int l = 0;
                int r = matrix[mid].size() - 1;

                while (l <= r){
                    int middle = l + (r - l) / 2;
                    if (target > matrix[mid][middle]) {
                        l = middle + 1;
                    } else if (target < matrix[mid][middle]) {
                        r = middle - 1;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};
