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
    const static int N = 9;
    vector<bool> used;

    bool check(char c) {
        if (c == '.') return true;
        if (used[c-'1']) return false;
        return used[c-'1'] = true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != N) return false;
        for (auto& row : board) if (row.size() != N) return false;

        // check row
        for (int i = 0; i < N; ++i) {
            used.assign(N, false);
            for (int j = 0; j < N; ++j)
                if (!check(board[i][j])) return false;
        }

        // check column
        for (int j = 0; j < N; ++j) {
            used.assign(N, false);
            for (int i = 0; i < N; ++i)
                if (!check(board[i][j])) return false;
        }

        // check 9-cells
        for (int k = 0; k < N; ++k) {
            used.assign(N, false);
            for (int i = k/3*3; i < k/3*3 + 3; ++i)
                for (int j = k%3*3; j < k%3*3 + 3; ++j)
                    if (!check(board[i][j])) return false;
        }

        return true;
    }
};
