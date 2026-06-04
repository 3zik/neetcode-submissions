class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        std::vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        std::queue<pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        // first we push in all the rotten fruit
        for (int r = 0; r < ROWS; ++r){
            for (int c = 0; c < COLS; ++c){
                if (grid[r][c] == 1){
                    fresh++;
                } else if (grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        // next we do bfs when possible
        // bfs is possible when we have rotten and we have fresh
        while (!q.empty() && fresh > 0){
            int length = q.size();
            // each timestep:
            for (int i = 0; i<length; ++i){
                // go thru the q
                const auto& curr = q.front();
                
                int r = curr.first;
                int c = curr.second;
                q.pop();
                // do 1 iteration bfs 
                for (int j = 0; j<4; ++j){
                    int row = r + directions[j][0];
                    int col = c + directions[j][1];
                    if (row >= 0 && col >= 0 &&
                        row < ROWS && col < COLS &&
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
