class Solution {
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        std::queue<pair<int, int>> q;
        int time = 0;
        for (int r = 0; r < grid.size(); ++r){
            for (int c = 0; c < grid[0].size(); ++c){
                if (grid[r][c] == 1){
                    fresh++;
                }
                else if (grid[r][c] == 2){
                    q.push({r, c});
                }
            }
        }

        while (!q.empty() && fresh > 0){
            int len = q.size();
            for (int i = 0; i < len; ++i){
                const auto& curr = q.front();
                int r = curr.first;
                int c = curr.second;
                q.pop();
                for (int j = 0; j < 4; ++j){
                    int row = r + dir[j][0];
                    int col = c + dir[j][1];
                    if (row >= 0 && col>=0 && row < grid.size() &&
                        col < grid[0].size() && grid[row][col] == 1){
                        q.push({row, col});
                        grid[row][col] = 2;
                        fresh--;
                    }
                }
            }
            time++;
        }
        return (fresh == 0) ? time : -1;
    }
};
