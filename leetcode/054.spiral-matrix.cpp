/*
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix
 *
 * Medium (25.01%)
 * Total Accepted:    90909
 * Total Submissions: 363490
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * 
 * 
 * For example,
 * Given the following matrix:
 * 
 * 
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 
 * 
 * You should return [1,2,3,6,9,8,7,4,5].
 * 
 */
class Solution {
public:
    vector<vector<int>> vv;
    vector<int> v;
    int m, n;

    void next(int k) {
        if (v.size() == m*n) return;

        for (int j = k; j < n-k; ++j) v.push_back(vv[k][j]);
        for (int i = k+1; i < m-k-1; ++i) v.push_back(vv[i][n-k-1]);
        if (m-k-1 > k)
            for (int j = n-k-1; j >= k; --j) v.push_back(vv[m-k-1][j]);
        if (n-k-1 > k)
            for (int i = m-k-2; i >= k+1; --i) v.push_back(vv[i][k]);

        next(k+1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vv = matrix;
        m = vv.size(); if (m == 0) return v;
        n = vv[0].size(); if (n == 0) return v;

        next(0);

        return v;
    }
};
