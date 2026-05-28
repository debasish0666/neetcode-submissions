class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // sets for rows
        unordered_set<char> rows[9];

        // sets for columns
        unordered_set<char> cols[9];

        // sets for 3x3 boxes
        unordered_set<char> boxes[9];

        for(int i = 0; i < 9; i++) {

            for(int j = 0; j < 9; j++) {

                char ch = board[i][j];

                // skip empty cells
                if(ch == '.') {
                    continue;
                }

                // box number
                int boxIndex = (i / 3) * 3 + (j / 3);

                // duplicate found
                if(rows[i].find(ch) != rows[i].end() ||
                   cols[j].find(ch) != cols[j].end() ||
                   boxes[boxIndex].find(ch) != boxes[boxIndex].end()) {

                    return false;
                }

                // insert into row, column and box
                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[boxIndex].insert(ch);
            }
        }

        return true;
    }
};