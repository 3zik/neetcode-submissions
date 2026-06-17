class Solution {
// this is my bottom up soln
// but we can optimize it by realizing we only need a 1d dp array
// 1. init dp as copy of bottom row
// 2. iterate from 2nd to last row -> top
// 3. for each position update dp[col] = triangle[row][col] + min()

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp (triangle.back());
        // initialized dp array to be a copy of the bottom row
        // of triangle

        for (int row = n - 2; row >= 0; --row){
            for (int col = 0; col < triangle[row].size(); ++col){
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }

        return dp[0];
    }
};