/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search
 *
 * Medium (25.81%)
 * Total Accepted:    114249
 * Total Submissions: 442633
 * Testcase Example:  '["ABCE","SFCS","ADEE"]\n"ABCCED"'
 *
 * 
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * 
 * 
 * For example,
 * Given board = 
 * 
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 
 * word = "ABCCED", -> returns true,
 * word = "SEE", -> returns true,
 * word = "ABCB", -> returns false.
 * 
 */
class Solution {
public:
    vector<vector<char>> vv;
    int m, n;

    bool next(int i, int j, const string &s) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;

        char c = vv[i][j];
        if (c == '\0') return false;
        if (c != s[0]) return false;

        string s1 = s.substr(1);
        if (s1.empty()) return true;

        vv[i][j] = '\0';
        bool x = next(i, j+1, s1) ||
                 next(i+1, j, s1) ||
                 next(i, j-1, s1) ||
                 next(i-1, j, s1);
        vv[i][j] = c;
        return x;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vv = board;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (next(i, j, word)) return true;
            }
        return false;
    }
};
