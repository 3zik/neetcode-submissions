class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        std::vector<vector<int>> directions = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < COLS; ++c){
                if (grid[r][c] == 1){
                    fresh++;
                } else if (grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }
        while (!q.empty() && fresh > 0) {
            int length = q.size();
            for (int i = 0; i < length; ++i){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (int j = 0; j < 4; ++j){
                    int row = r + directions[j][0];
                    int col = c + directions[j][1];
                    if (row < ROWS && row >= 0 &&
                        col < COLS && col >= 0 &&
                        grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
