class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        std::queue<pair<int, int>> q;
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int r = 0; r < grid.size(); ++r){
            for (int c = 0; c < grid[0].size(); ++c){
                if (grid[r][c] == 0){
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()){
            const auto& curr = q.front();
            int row = curr.first;
            int col = curr.second;
            q.pop();
            for (int i = 0; i < 4; ++i){
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if (r < 0 || c < 0 || r >= grid.size() ||
                    c >= grid[0].size() || grid[r][c] != INT_MAX){
                    continue;
                }
                grid[r][c] = grid[row][col] + 1;
                
                q.push({r,c});
            }
        }
    }
};
