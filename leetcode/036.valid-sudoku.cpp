/*
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku
 *
 * Medium (34.42%)
 * Total Accepted:    109671
 * Total Submissions: 318612
 * Testcase Example:  '[".87654321","2........","3........","4........","5........","6........","7........","8........","9........"]'
 *
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only
 * the filled cells need to be validated.
 * 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9) return false;
        for (auto& row : board) if (row.size() != 9) return false;

        int all = 0, b = 0;
        // check row
        for (int i = 0; i < 9; ++i) {
            all = 0;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                b = 1 << (board[i][j] - '0');
                if (b & all) return false;
                all |= b;
            }
        }

        // check column
        for (int j = 0; j < 9; ++j) {
            all = 0;
            for (int i = 0; i < 9; ++i) {
                if (board[i][j] == '.') continue;
                b = 1 << (board[i][j] - '0');
                if (b & all) return false;
                all |= b;
            }
        }

        // check 9-cells
        for (int k = 0; k < 9; ++k) {
            all = 0;
            for (int i = k/3*3; i < k/3*3 + 3; ++i)
                for (int j = k%3*3; j < k%3*3 + 3; ++j) {
                    if (board[i][j] == '.') continue;
                    b = 1 << (board[i][j] - '0');
                    if (b & all) return false;
                    all |= b;
                }
        }

        return true;
    }
};
