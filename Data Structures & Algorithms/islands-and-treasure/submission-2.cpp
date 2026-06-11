class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()){
            const auto& curr = q.front();
            int row = curr.first;
            int col = curr.second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                if (r < 0 || r >= m || c < 0||
                    c >= n || grid[r][c] != INT_MAX){
                    continue;        
                }
                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};
