class Solution {
public:
std::vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0, -1}};
    int dfs(vector<vector<int>>&grid, int r, int c){
        int res = 1;
        if (r < 0 || r >= grid.size() || c < 0 ||
            c >= grid[0].size() || grid[r][c] == 0){
            return 0;
        }

        grid[r][c] = 0;
        for (int i = 0; i < 4; ++i){
            res += dfs(grid, r+dir[i][0], c+dir[i][1]);
        }
        return res;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int r = 0; r < grid.size(); ++r){
            for (int c = 0; c < grid[0].size(); ++c){
                if (grid[r][c] == 1){
                    maxArea = std::max(dfs(grid, r, c), maxArea);
                }
            }
        }
        return maxArea;
    }
};
