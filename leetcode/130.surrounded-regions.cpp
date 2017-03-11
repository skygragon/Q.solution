/*
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions
 *
 * Medium (17.74%)
 * Total Accepted:    74397
 * Total Submissions: 419314
 * Testcase Example:  '["XXXX","XOOX","XXOX","XOXX"]'
 *
 * 
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * 
 * 
 * For example,
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 
 * 
 * After running your function, the board should be:
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 */
class Solution {
public:
    vector<vector<char>> vv;
    int m, n;

    void mark(int i, int j, char c) {
        if (vv[i][j] != 'O') return;

        stack<pair<int, int>> s;
        s.push({i, j});

        while (!s.empty()) {
            auto p = s.top(); s.pop();
            int x = p.first, y = p.second;
            vv[x][y] = c;

            if (x > 1 && vv[x-1][y] == 'O') s.push({x-1, y});
            if (x < m-1 && vv[x+1][y] == 'O') s.push({x+1, y});
            if (y > 1 && vv[x][y-1] == 'O') s.push({x, y-1});
            if (y < n-1 && vv[x][y+1] == 'O') s.push({x, y+1});
        }
    }

    void solve(vector<vector<char>>& board) {
        vv = board;
        m = vv.size(); if (m == 0) return;
        n = vv[0].size(); if (n == 0) return;

        for (int i = 0; i < m; ++i) mark(i, 0, 'o');
        for (int i = 0; i < m; ++i) mark(i, n-1, 'o');
        for (int j = 0; j < n; ++j) mark(0, j, 'o');
        for (int j = 0; j < n; ++j) mark(m-1, j, 'o');

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (vv[i][j] == 'O') mark(i, j, 'X');
            }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (vv[i][j] == 'o') vv[i][j] = 'O';
            }
        board = vv;
    }
};
