class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map <int, unordered_set<char>> row, col; // a vector of char for each row and col
        map <pair <int, int> , unordered_set<char>> square; // a collection of 3x3 with its char contents

        for(int r =0; r<9 ; r++){
            for (int c = 0; c<9 ; c++){
                
                char digit = board[r][c]; // storing value for simplicity

                if(digit == '.') // if value is empty
                    continue;

                pair <int, int> sk = {r/3, c/3}; // sk --> squuareKey

                if(row[r].count(digit) || col[c].count(digit) || square[sk].count(digit))
                    return false; // if digit is already present in current row/col/3x3
                                // then the sudoku is not valid


                // storing value into row col and 3x3 checker to make sure it doesnt repeat
                row[r].insert(digit);
                col[c].insert(digit);
                square[sk].insert(digit);
            }
        }

        //all conditions have been met
        return true;
         
    }
};
