class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // create 3 hash maps of sets
        // rows to track digits in each row
        // cols to track digits in each col
        // squares to track digits in each 3x3 sub box 
        std::unordered_map<int, std::unordered_set<char>> rows, cols;
        std::map<std::pair<int, int>, std::unordered_set<char>> squares;

        // loop through every cell in the board
        // skip the cell if it contains "."
        // if val is already in rows[r] or cols[c] or squares[]
            // then return false
        // otherwise add it to all three sets

        for (int r = 0; r < board.size(); ++r){
            for (int c = 0; c < board[0].size(); ++c){
                if (!(board[r][c] == '.')) {
                    std::pair<int, int> squareKey = {r / 3, c / 3};

                    if (rows[r].count(board[r][c]) || 
                        cols[c].count(board[r][c]) ||
                        squares[squareKey].count(board[r][c])) {
                        return false;
                    } else {
                        rows[r].insert(board[r][c]);
                        cols[c].insert(board[r][c]);
                        squares[squareKey].insert(board[r][c]);
                    }
                }
            }
        }
        return true;
    }
};
