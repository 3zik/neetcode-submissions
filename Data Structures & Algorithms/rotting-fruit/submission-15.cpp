class Solution {
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int time = 0;
        queue<pair<int,int>> q;
        for (int r = 0; r < grid.size(); ++r){
            for (int c = 0; c < grid[0].size(); ++c){
                if (grid[r][c] == 1){
                    fresh++;
                } else if (grid[r][c] == 2){
                    q.push({r,c});
                }
            }
        }

        while (!q.empty() && (fresh > 0)){
            int len = q.size();
            for (int i = 0; i < len; ++i){
                const auto& curr = q.front();
                int row = curr.first;
                int col = curr.second;
                q.pop();
                for (int j = 0; j < 4; ++j){
                    int r = row + dir[j][0];
                    int c = col + dir[j][1];
                    if (r >= 0 && c >= 0 && r < grid.size() &&
                        c < grid[0].size() && grid[r][c] == 1){
                        q.push({r, c});
                        grid[r][c] = 2;
                        fresh--;
                    }
                }
            }
            time++;
        }
        return (fresh == 0) ? time : -1;
    }
};
