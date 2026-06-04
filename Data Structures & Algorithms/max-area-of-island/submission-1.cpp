class Solution {
std::vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int res = 1;

        if (r < 0 || c < 0 || c >= COLS ||
            r >= ROWS || grid[r][c] == 0) {
            return 0;
        }
        grid[r][c] = 0;

        for (int i = 0; i < 4; ++i) {
            res += dfs(grid, r + directions[i][0], c + directions[i][1]);
        }

        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int maxArea = 0;

        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < COLS; ++c){
                if (grid[r][c] == 1) {
                    int area = dfs(grid, r, c);
                    maxArea = std::max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};
