/*
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii
 *
 * Medium (38.40%)
 * Total Accepted:    74256
 * Total Submissions: 193372
 * Testcase Example:  '0'
 *
 * Given an integer n, generate a square matrix filled with elements from 1 to
 * n2 in spiral order.
 * 
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    int x;

    void drawCircle(int k, int len) {
        if (len == 1) {
            vv[k][k] = ++x;
            return;
        }

        for (int j = k; j < k + len - 1; ++j) vv[k][j] = ++x;
        for (int i = k; i < k + len - 1; ++i) vv[i][k+len-1] = ++x;
        for (int j = k+len-1; j > k; --j) vv[k+len-1][j] = ++x;
        for (int i = k+len-1; i > k; --i) vv[i][k] = ++x;
    }

    vector<vector<int>> generateMatrix(int n) {
        x = 0;
        vv.resize(n);
        for (auto& v : vv) v.resize(n);

        int k = 0;
        while (n > 0) {
            drawCircle(k, n);
            n -= 2; ++k;
        }

        return vv;
    }
};
