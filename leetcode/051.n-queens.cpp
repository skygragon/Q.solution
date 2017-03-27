/*
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens
 *
 * Hard (29.70%)
 * Total Accepted:    74116
 * Total Submissions: 249311
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * 
 * [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<string>> vv;
    vector<string> v;
    int n;

    vector<bool> col, l, r;

    void next(int i) {
        if (i == n) {
            vv.push_back(v);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (col[j] || l[i+j] || r[n-1+i-j]) continue;

            col[j] = l[i+j] = r[n-1+i-j] = true;
            v[i][j] = 'Q';

            next(i+1);

            col[j] = l[i+j] = r[n-1+i-j] = false;
            v[i][j] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        v.resize(n, string(n, '.'));
        col.resize(n, false);
        l.resize(2*n-1, false);
        r.resize(2*n-1, false);

        next(0);
        return vv;
    }
};
