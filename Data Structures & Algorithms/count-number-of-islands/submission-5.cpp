class Solution {
std::vector<vector<int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
public:
    void dfs(vector<vector<char>>& grid, int r, int c){
        int ROWS = grid.size();
        int COLS = grid[0].size();
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            return;
        }
        if (grid[r][c] == '0'){
            return ;
        }
        if (grid[r][c] == '1'){
            grid[r][c] = '0';
        }
        for (int i =0; i<4;++i){
            dfs(grid, r+directions[i][0], c+directions[i][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c<COLS;++c){
                if (grid[r][c] == '1'){
                    islands++;
                    dfs(grid, r,c);
                }
            }
        }
        return islands;
        
    }
};
