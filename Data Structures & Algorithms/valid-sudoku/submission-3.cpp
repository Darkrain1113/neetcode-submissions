class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<std::string> seen;
        

        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++ ){
                if (board[row][col] != '.') {
                    char val = board[row][col];


                std::string row_str = std::string(1, val) + " at row " + std::to_string(row);
                    std::string col_str = std::string(1, val) + " at col " + std::to_string(col);
                    std::string box_str = std::string(1, val) + " at box " + std::to_string(row / 3) + "-" + std::to_string(col / 3);

                    // If any of these strings are already in the set, the board is invali
                    if (seen.count(row_str) || seen.count(col_str) || seen.count(box_str)) {
                        return false;
                    }

                    // Otherwise, add them to our tracking set
                    seen.insert(row_str);
                    seen.insert(col_str);
                    seen.insert(box_str);
                }
            }
        }
        return true;
    }
};



             
