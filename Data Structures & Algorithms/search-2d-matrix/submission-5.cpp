class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()-1;
        int mid;
        while (l <= r){
            mid = l + ((r-l) / 2);
            if (matrix[mid][matrix[mid].size() - 1] < target){
                l = mid + 1;
            } else if (matrix[mid][matrix[mid].size() - 1] > target){
                r = mid - 1;
            } else {
                return true;
            }
        }

        if (l >= matrix.size()) return false;

        mid = l;
        // Now, we know we are at the "mid" row
        // do bin search again for this row

        l = 0;
        r = matrix[mid].size()-1;
        while (l <= r){
            int new_mid = l + ((r-l) / 2);
            if (matrix[mid][new_mid] < target){
                l = new_mid + 1;
            } else if (matrix[mid][new_mid] > target){
                r = new_mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
