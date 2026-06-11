class Solution {
std::vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs(vector<vector<char>>& grid, int row, int col){
    if (row < 0 || col < 0 || col >= grid[0].size() ||
        row >= grid.size() || grid[row][col] == '0'){
        return ;
    }
    grid[row][col] = '0';
    for (int i = 0; i < 4; ++i){
        dfs(grid, row + dir[i][0], col + dir[i][1]);
    }
}

public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for (int r = 0; r < grid.size(); ++r){
            for (int c = 0; c < grid[0].size();++c){
                if (grid[r][c] == '1'){
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }
        return islands;
    }
};
